#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
typedef long long LL;
const int maxn = 1000005;
const int mod = 1e9+7;

int f[maxn],g[maxn],T[maxn],G[maxn],pw2[maxn];
int inc(int u,int v) {u+=v;u>=mod?u-=mod:0;return u;}
int dec(int u,int v) {u-=v;u<0?u+=mod:0;return u;}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("kibibits.in","r",stdin);
		freopen("kibibits.out","w",stdout);
	#endif
	int n;scanf("%d",&n);pw2[0]=1;
	for (int i=1;i<=n;i++)
		pw2[i]=(pw2[i-1]<<1)%mod;
	for (int x,i=1;i<=n;i++)
		scanf("%d",&x),T[x]++,f[x]=(f[x]+x)%mod,g[x]=(g[x]+(LL)x*x)%mod;
	for (int i=1;i<=100000;i*=10)
	for (int j=0;j<=999999;j++)
	if ((j/i)%10==9) {
		for (int o=1,k=j;o<=9;o++,k-=i)
		{
			f[k-i]=inc(f[k-i],f[k]);
			g[k-i]=inc(g[k-i],g[k]);
			T[k-i]=inc(T[k-i],T[k]);
		}
	}
	for (int i=0;i<=999999;i++)
	{
		if (T[i]==0) G[i]=0;
		if (T[i]==1) G[i]=g[i];
		if (T[i]>1)
			G[i]=((LL)f[i]*f[i]+g[i])%mod*pw2[(T[i]-2)]%mod;
	}
	for (int i=1;i<=100000;i*=10)
	for (int j=0;j<=999999;j++)
	if ((j/i)%10==0) {
		for (int o=1,k=j;o<=9;o++,k+=i)
		{
			G[k]=dec(G[k],G[k+i]);
		}
	}
	
	LL res=0;
	for (int i=0;i<=999999;i++) 
	{
		LL t=(LL)i*G[i];res^=t;
	}
	printf("%lld",res);
	return 0;
}