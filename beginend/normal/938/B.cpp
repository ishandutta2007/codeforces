#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;
const int inf=1000000;

int n,a[N];

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
	for (int i=1;i<=n;i++) a[i]=read();
	int l=0,r=n+1,ans=0;
	while (l+1<r)
	{
		if (a[l+1]-1<=inf-a[r-1]) l++,ans=max(ans,a[l]-1);
		else r--,ans=max(ans,inf-a[r]);
	}
	printf("%d",ans);
	return 0;
}