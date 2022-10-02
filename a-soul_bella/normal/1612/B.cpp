#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int main()
{
	int t,n,a,b;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		a=read();
		b=read();
		if(b<n/2||a>n/2+1)
		{
			printf("-1\n");
			continue;
		}
		//printf("?\n");
		if(a>n/2-(n-b)+a-1&&a<b+1)
		{
			printf("-1\n");
			continue;
		}
		if(b>a-1&&n/2-(n-b)+a>b)
		{
			printf("-1\n");
			continue;
		}
		for(int i=b+1;i<=n;i++)printf("%d ",i);
		for(int i=a;i<=n/2-(n-b)+a-1;i++)printf("%d ",i);
		for(int i=1;i<=a-1;i++)printf("%d ",i);
		for(int i=n/2-(n-b)+a;i<=b;i++)printf("%d ",i);
		printf("\n");
	}
}