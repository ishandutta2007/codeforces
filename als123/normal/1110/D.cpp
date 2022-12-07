#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1000005;
int n,m;
int a[N];
int f[2][9][9];
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)	{int x;scanf("%d",&x);a[x]++;}
/*	for (int u=1;u<=m;u++) printf("%d ",a[u]);
	printf("\n");*/
	int ans=0;
	for (int u=1;u<=m;u++)
	{
		while (a[u]>=9)	{a[u]-=3;ans++;}
	}
	int now=0;
	for (int u=0;u<=a[1];u++)
	for (int i=0;i<=a[2];i++)
	f[now][u][i]=(a[1]-u)/3+(a[2]-i)/3;
	for (int u=3;u<=m;u++)
	{
		now^=1;
		memset(f[now],0,sizeof(f[now]));
		for (int i=0;i<=a[u-2];i++)
		for (int j=0;j<=a[u-1];j++)
		{
			for (int k=0;k<=a[u];k++)
			{
				int t=min(k,min(i,j));
				f[now][j-t][k-t]=max(f[now][j-t][k-t],t+(a[u]-k)/3+f[now^1][i][j]);
			}
		}
	}
	int mx=0;
	for (int u=0;u<=a[m-1];u++)
	for (int i=0;i<=a[m];i++)
	mx=max(mx,f[now][u][i]);
	printf("%d\n",ans+mx);
	return 0;
}