#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=10005;
LL n,k;
LL ans=1;
LL f[N][61];
LL sum[61];
LL inv[61];
void calc (LL xx,LL x)
{
//	printf("%lld %lld\n",xx,x);
	f[0][x]=1;for (LL u=0;u<x;u++) f[0][u]=0;
	for (LL u=1;u<=k;u++)
	{
		for (LL i=0;i<=x;i++)
		{
			f[u][i]=0;
			for (LL j=i;j<=x;j++)
				f[u][i]=(f[u][i]+f[u-1][j]*inv[j+1]%MOD)%MOD;
		}
	}
	LL lalal=0,now=1;
	for (LL i=0;i<=x;i++)
	{
		//printf("YES:%lld %lld\n",f[k][i],now);
		lalal=(lalal+now*f[k][i]%MOD)%MOD;
		now=now*xx%MOD;
	}
	ans=ans*lalal%MOD;
}
int main()
{
	inv[1]=1;for (LL u=2;u<=60;u++) inv[u]=(MOD-MOD/u)*inv[MOD%u]%MOD;
	scanf("%lld%lld",&n,&k);
	for (LL u=2;u*u<=n;u++)
	{
		LL i=0;
		while (n%u==0)	{n/=u;i++;}
		if (i==0) continue;
		calc(u,i);
	}
	if (n!=1)	calc(n,1);
	printf("%lld\n",ans);
	return 0;
}