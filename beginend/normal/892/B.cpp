#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=1000005;

int n;
LL a[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		a[max(0,i-x)]++;a[i]--;
	}
	int ans=0;
	for (int i=1;i<=n;i++) a[i]+=a[i-1],ans+=(!a[i]?1:0);
	printf("%d",ans);
	return 0;
}