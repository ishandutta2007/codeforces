#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=2000005;
int a[N];
int n;
int f[N],f1[N];
bool Ins (int x,int xx)
{
	int now=x;
	for (int u=xx-1;u>=0;u--)
	{
		if ((1<<u)&now)
		{
			if (f[u]==0) {f[u]=now;f1[u]=x;return true;}
			else now^=f[u];
		}
	}
	return false;
}
int last[N],g[N];
bool solve (int x)
{
	for (int u=0;u<=x;u++) f[u]=0;
	int up=(1<<x)-1;
	int o=0,cnt=0;
	for (int u=1;u<=n;u++) if (a[u]<=up)
	{
		if (Ins(a[u],x)==false) o=a[u];
		else cnt++;
	}
	//printf("%d %d\n",x,cnt);
	if (cnt==x)
	{
		g[0]=0;g[1]=1;
		last[0]=0;last[1]=1;
		for (int u=2;u<=x;u++)
		{
			int t1=(1<<u)-1,t2=(1<<u-1)-1;
			for (int i=0;i<=t2;i++)
			{
				g[i]=last[i];
				g[t1-i]=(1<<u-1)+last[i];
			}
			for (int i=0;i<=t1;i++) last[i]=g[i];
		}
		printf("%d\n",x);
		for (int u=0;u<=up;u++)
		{
			//printf("%d\n",g[u]);
			int ans=0;
			for (int i=0;i<x;i++)
			 if (g[u]&(1<<i))
			 ans^=f1[i];
			printf("%d ",ans);
		}
		return true;
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=30;u>=1;u--) if (solve(u)) return 0;
	printf("0\n0");
	return 0;
}