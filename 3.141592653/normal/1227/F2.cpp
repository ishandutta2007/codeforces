#include<cstdio>
#include<cstring>
typedef long long ll;
typedef double db;
const ll mod=998244353;
int n,k;
int a[222222];
inline ll qpow(ll x,ll k)
{
	ll r=1;
	x=(x+mod)%mod;
	for(;k;k>>=1,(x*=x)%=mod)if(k&1)(r*=x)%=mod;
	return r;
}
ll fac[222222],inv[222222];
inline ll C(ll n,ll r)
{return (fac[n]*((inv[r]*inv[n-r])%mod))%mod;}
int main()
{
	scanf("%d%d",&n,&k);
	register int i,ii;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	fac[0]=1;
	for(i=1;i<=n;i++)
		fac[i]=(fac[i-1]*i)%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(i=n-1;~i;i--)
		inv[i]=(inv[i+1]*(i+1))%mod;
	a[n+1]=a[1];
	ll g=0,s=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]^a[i+1])g++;
		else(s*=k)%=mod;
	}ll rem=s;
	ll tt=qpow(k,g);
	(s*=tt)%=mod;
	k-=2;
	ll dec=1,dd=(k*1ll*k)%mod;
	if(g&1)(dec*=k)%=mod;
	for(i=(g>>1);~i;i--)
	{
		ll x=C(g,i),y=(x*C(g-i,i))%mod;
		ll d=dec;
		(d*=y)%=mod;(s-=d*rem)%=mod;(s+=mod)%=mod;(dec*=dd)%=mod;
	}printf("%I64d\n",(s*qpow(2,mod-2))%mod);
}