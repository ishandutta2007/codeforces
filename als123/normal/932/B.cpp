#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1e6+5;
int f[N];
int g[N];
int sum[N][10];
int get (int x)
{
	int ans=1;
	while (x>0)
	{
		if (x%10!=0) ans=ans*(x%10);
		x/=10;
	}
	return ans;
}
int main()
{
	for (int u=1;u<=1000000;u++)	f[u]=get(u);
	for (int u=1;u<10;u++) g[u]=u;
	for (int u=10;u<=1000000;u++)
		g[u]=g[f[u]];
	for (int u=1;u<=1000000;u++)
	{
		for (int i=1;i<=9;i++) sum[u][i]=sum[u-1][i];
		if (g[u]<=9) sum[u][g[u]]++;
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",sum[r][k]-sum[l-1][k]);
	}
	return 0;
}