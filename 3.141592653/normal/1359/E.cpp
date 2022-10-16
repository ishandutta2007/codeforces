#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
cpnst ll mod=998244353;
ll qpow(ll x,ll k)
{ll r=1;for(;k;k>>=1,(x*=x)%=mod)if(k&1)(r*=x)%=mod;return r;}
ll fac[1111111],inv[1111111];
void precalc()
{
	register int i;
	int R=1e6;
	for(i=fac[0]=1;i<=R;i++)
		fac[i]=fac[i-1]*i%mod;
	for(i=R-1,inv[R]=qpow(fac[R],mod-2);~i;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(ll n,ll r)
{return(n<r||n<0)?0:fac[n]*inv[r]%mod*inv[n-r]%mod;}
int main()
{
	precalc();
	int n,k;
	scanf("%d%d",&n,&k);
	register int i;
	ll ans=0;
	for(i=1;i<=n;i++)
		ans+=C(n/i-1,k-1);
	printf("%lld\n",ans%mod);
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/