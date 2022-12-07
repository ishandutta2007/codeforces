#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=1000005;
const LL MOD=1e9+7;
LL gcd (LL x,LL y)	{return x==0?y:gcd(y%x,x);}
LL fa[N],siz[N];
LL n;
LL f[N];
LL g[N];
int main()
{
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++) scanf("%I64d",&siz[u]);
	for (LL u=2;u<=n;u++) scanf("%I64d",&fa[u]);
	for (LL u=n;u>=2;u--)	siz[fa[u]]=siz[fa[u]]+siz[u];
	for (LL u=1;u<=n;u++)
	{
		LL t=siz[1]/gcd(siz[1],siz[u]);
	//	printf("YES:%lld\n",siz[u]);
		if (t<=n) f[t]++;
	}
	for (LL u=1;u<=n;u++)
	{
		for (LL i=u;i<=n;i+=u)
			g[i]=g[i]+f[u];
		f[u]=0;
	}
	LL ans=0;
	f[1]=1;
	for (LL u=1;u<=n;u++)
	{
	//	printf("YES:%lld %lld\n",u,g[u]);
		if (siz[1]%u==0&&g[u]==u)
		{
			ans=(ans+f[u])%MOD;
			for (LL i=u+u;i<=n;i+=u) f[i]=(f[i]+f[u])%MOD;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}