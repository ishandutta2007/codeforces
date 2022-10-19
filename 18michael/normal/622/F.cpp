#include<cstdio>
#define LL long long
#define mod 1000000007
LL n,k,k1,k2,ans=0,T=1;
LL fac[1000005],inv[1000005],G[1000005];
inline LL pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
int main()
{
	scanf("%lld%lld",&n,&k),k1=k+1,k2=k+2,fac[0]=1,G[0]=0;
	for(LL i=1;i<=k2;++i)fac[i]=(fac[i-1]*i)%mod,G[i]=(G[i-1]+pow(i,k))%mod;
	inv[k2]=pow(fac[k2],mod-2);
	for(LL i=k2;i;--i)inv[i-1]=(inv[i]*i)%mod;
	if(n>k2)
	{
		for(LL i=1;i<=k2;++i)ans=(ans+((((G[i]*inv[i-1])%mod)*inv[k2-i]*(((k2-i)&1)? -1:1))%mod)*pow(n-i,mod-2))%mod,T=(T*(n-i))%mod;
		ans=(ans*T)%mod;
	}
	else ans=G[n];
	printf("%lld",(ans+mod)%mod);
	return 0;
}