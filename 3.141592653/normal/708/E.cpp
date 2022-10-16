#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n,m;
typedef long long ll;
ll a,b,k;
cpnst ll mod=1e9+7;
ll f[2222][2222],t[2222][2222],g[2222][2222];
ll q[2222],s[2222];
ll qpow(ll x,ll k)
{ll r=1;for(;k;k>>=1,(x*=x)%=mod)if(k&1)(r*=x)%=mod;return r;}
ll fac[1111111],inv[1111111];
ll C(ll n,ll r)
{return fac[n]*inv[r]%mod*inv[n-r]%mod;}
int main()
{
	scanf("%d%d%lld%lld%lld",&n,&m,&a,&b,&k);
	ll gg=(mod+b-a)%mod;
	register int i,ii;
	for(i=fac[0]=1;i<=k;i++)
		fac[i]=fac[i-1]*i%mod;
	for(i=k-1,inv[k]=qpow(fac[k],mod-2);~i;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
	for(i=0;i<=m&&i<=k;i++)
		q[i]=qpow(a,i)*qpow(gg,k-i)%mod*C(k,i)%mod;
	for(i=0;i<=m;i++)s[i]=q[i];
	for(i=1;i<=m;i++)(s[i]+=s[i-1])%=mod;
	f[0][1]=1;
	for(i=1;i<=m;i++)t[0][i]=(t[0][i-1]+f[0][i])%mod;
	for(i=1;i<=m;i++)g[0][i]=(g[0][i-1]+t[0][m-i+1]*q[i-1])%mod;
	for(i=1;i<=n;i++)
	{
		for(ii=1;ii<=m;ii++)
			f[i][ii]=q[ii-1]*(s[m-ii]*(t[i-1][m-ii+1]-t[i-1][m])%mod+g[i-1][m-ii+1])%mod;
		for(ii=1;ii<=m;ii++)t[i][ii]=(t[i][ii-1]+f[i][ii])%mod;
		for(ii=1;ii<=m;ii++)g[i][ii]=(g[i][ii-1]+t[i][m-ii+1]*q[ii-1])%mod;
	}ll sum=0;
	for(i=1;i<=m;i++)(sum+=f[n][i])%=mod;(sum+=mod)%=mod;
	printf("%lld\n",sum*qpow(qpow(b,mod-2),n*k*2)%mod);
}
/*
Just go for it.
*/