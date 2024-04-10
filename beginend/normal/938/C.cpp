#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	int T=read();
	while (T--)
	{
		n=read();
		if (!n) {printf("%d %d\n",1,1);continue;}
		int flag=0;
		for (int i=1;i*i<=n;i++)
			if (n%i==0)
			{
				if ((i&1)!=((n/i)&1)||i*i==n) continue;
				int x=(i+n/i)/2,y=(n/i-i)/2;
				if (x/(x/y)!=y) continue;
				printf("%d %d\n",x,x/y);
				flag=1;break;
			}
		if (!flag) puts("-1");
	}
	return 0;
}