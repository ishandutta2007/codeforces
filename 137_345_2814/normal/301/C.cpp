#include<cstdio>
using namespace std;
int main()
{
	for(int i=0;i<=9;i++)printf("???%d>>%d???\n",i,i);
	printf("???>>??\n");
	for(int i=0;i<9;i++)printf("%d??>>?%d\n",i,i+1);
	printf("9??>>??0\n");
	for(int i=0;i<=9;i++)printf("%d?>>?%d\n",i,i);
	printf("??<>1\n?<>\n>>???\n");
}