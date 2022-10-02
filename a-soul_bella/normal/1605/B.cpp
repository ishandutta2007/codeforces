#include<iostream>
#include<cstdio>
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
char str[100005];
int main()
{
	int t,n,sl=0,ans=0;
	t=read(); 
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",str+1);
		sl=0;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='1')sl++;
		}
		ans=0;
		for(int i=1;i<=n-sl;i++)
		{
			if(str[i]=='1')ans++;
		}
		for(int i=n-sl+1;i<=n;i++)
		{
			if(str[i]=='0')ans++;
		}
		if(ans==0)
		{
			printf("0\n");
			continue;
		}
		printf("1\n");
		printf("%d ",ans);
		for(int i=1;i<=n-sl;i++)
		{
			if(str[i]=='1')printf("%d ",i);
		}
		for(int i=n-sl+1;i<=n;i++)
		{
			if(str[i]=='0')printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}