#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;
const int inf=(int)2e9;

int n,m,a[N],suf[N],pre[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (m==1)
	{
		int mn=a[1];
		for (int i=2;i<=n;i++) mn=min(mn,a[i]);
		printf("%d",mn);
	}
	else if (m==2)
	{
		pre[1]=a[1];
		for (int i=2;i<=n;i++) pre[i]=min(pre[i-1],a[i]);
		suf[n]=a[n];
		for (int i=n-1;i>=1;i--) suf[i]=min(suf[i+1],a[i]);
		int ans=-inf;
		for (int i=1;i<n;i++) ans=max(ans,max(pre[i],suf[i+1]));
		printf("%d",ans);
	}
	else
	{
		int mx=a[1];
		for (int i=2;i<=n;i++) mx=max(mx,a[i]);
		printf("%d",mx);
	}
	return 0;
}