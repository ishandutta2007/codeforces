#include<cstdio>
int k,a=(1<<17);
int main()
{
	scanf("%d",&k),printf("2 3\n%d %d 0\n%d %d %d",a+k,k,a+(a+(~k)),a+k,k);
	return 0;
}