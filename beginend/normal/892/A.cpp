#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

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
	n=read();LL s=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();s+=(LL)x;
	}
	int mx1=0,mx2=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (x>mx1) mx2=mx1,mx1=x;
		else if (x>mx2) mx2=x;
	}
	if (s<=(LL)mx1+(LL)mx2) puts("YES");
	else puts("NO");
	return 0;
}