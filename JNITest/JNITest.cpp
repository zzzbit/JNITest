// JNITest.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "MyInterface.h"
#include "TestInterface.h"
#include <windows.h>
typedef double(*Dllfun)(double * feature1, double * feature2, int * dim, int totalDim, int classNum, bool gaussFileType, char * gaussFile1,char * gaussFile2, double covMin, int histCalType);
JNIEXPORT jdouble JNICALL Java_MyInterface_ISC_1SimiComputing
	(JNIEnv *env, jobject jobj, jdoubleArray jda1, jdoubleArray jda2, jintArray ja1, jint totalDim, jint classNum, jboolean gaussFileType, jcharArray jca1, jcharArray jca2, jdouble covMin, jint histCalType){
		//jdouble* feature1 = env ->GetDoubleArrayElements(jda1,0);
		//jsize feature1_len = env ->GetArrayLength(jda1);
		//jdouble* feature2 = env ->GetDoubleArrayElements(jda2,0);
		//jint* jdim = env->GetIntArrayElements(ja1,0);
		//int* dim = (int*)jdim;
		//jchar* jgaussFile1 = env->GetCharArrayElements(jca1,0);
		//jchar* jgaussFile2 = env->GetCharArrayElements(jca2,0);
		//char* gaussFile1 = (char*)jgaussFile1;
		//char* gaussFile2 = (char*)jgaussFile2;
		//int i;
		//for (i = 0; i < feature1_len; i++){
		//	printf("%lf ",feature1[i]);
		//}

		Dllfun SimiComputing;
		HINSTANCE hdll;
		hdll = LoadLibrary(L"SC_SimiComputing.dll");
		if(hdll==NULL)
		{
			FreeLibrary(hdll);
		}
		SimiComputing = (Dllfun)GetProcAddress(hdll,"ISC_SimiComputing");
		if(SimiComputing==NULL)
		{
			FreeLibrary(hdll);
		}
		double mfeature1[]= {1.2,2.3,3.4};
		double mfeature2[]= {1.2,2.3,4.5};
		int mdim[]= {1,1,1};
		char mgaussFile[] = "C:\\Test\\shapeMMP2.0_0_new.txt";
		char mgaussFile2[] = "C:\\Test\\shapeMMP2.0_1_new.txt";
		//jdouble c=SimiComputing(feature1,feature2,dim,totalDim,classNum,gaussFileType,gaussFile1,gaussFile2,covMin,histCalType);
		jdouble c=2;
		c =SimiComputing(mfeature1, mfeature2, mdim, 3, 2, true, mgaussFile, mgaussFile2, 0.00000025, 2);
		printf("%ld\n",c);
		FreeLibrary(hdll);
		return c;
}
JNIEXPORT jint JNICALL Java_TestInterface_add
	(JNIEnv *, jobject, jint a, jint b){
		int c = a + b;
		return c;
}