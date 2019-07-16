
#include <jni.h>  /* /usr/lib/jvm/java-1.7.0-openjdk-amd64/include/ */
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>


//test
 
#if 0
typedef struct {
    char *name;          /* Java里调用的函数名 */
    char *signature;    /* JNI字段描述符, 用来表示Java里调用的函数的参数和返回值类型 */
    void *fnPtr;          /* C语言实现的本地函数 */
} JNINativeMethod;
#endif

jint ledOpen(JNIEnv *env, jobject cls)
{	
__android_log_print(ANDROID_LOG_DEBUG,"JNIDemo","native open ...");
	return 0;
}

void LedClose(JNIEnv *env, jobject cls)
{	
__android_log_print(ANDROID_LOG_DEBUG,"JNIDemo","native close ...");
}

jint LedCtrl(JNIEnv *env, jobject cls,jint which,jint status)
{	
__android_log_print(ANDROID_LOG_DEBUG,"JNIDemo","native ctrl:%d,%d",which,status);
	return 0;
}

static const JNINativeMethod methods[] = {
	{"ledOpen", "()I", (void *)ledOpen},
	{"LedCtrl", "(II)I", (void *)LedCtrl},
	{"LedClose", "()V", (void *)LedClose},
};




/* System.loadLibrary */
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	jclass cls;

	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
		return JNI_ERR; /* JNI version not supported */
	}
	cls = (*env)->FindClass(env, "com/jingxing/hardlibrary/HardControl");
	if (cls == NULL) {
		printf("eeeeeee\n");
		return JNI_ERR;
		//return JNI_FALSE;
	}

	/* 2. map java hello <-->c c_hello */
	if ((*env)->RegisterNatives(env, cls, methods, 3) < 0)
{
		printf("eeeeee0e\n");
		return JNI_ERR;
		//return JNI_FALSE;
}
	return JNI_VERSION_1_4;
}

