#include<cstdio>
#include<cstring>
typedef long long ll;
int n;
ll a[1111111];
const ll mod=998244353;
inline ll qpow(ll x,ll k)
{ll r=1;for(;k;k>>=1,(x*=x)%=mod)if(k&1)(r*=x)%=mod;return r;}
inline ll rev(ll x)
{return qpow(x,mod-2);}
inline ll dev(ll x)
{return(mod+1-x)%mod;}
ll dp[1111111];
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]),a[i]=(100ll*rev(a[i]))%mod;
	dp[1]=a[1];
	for(i=2;i<=n;i++)
		dp[i]=((dp[i-1]+1)*a[i])%mod;
	printf("%d\n",dp[n]);
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/