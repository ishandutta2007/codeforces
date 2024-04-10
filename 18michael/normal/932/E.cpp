#include<cstdio>
#define LL long long
#define mod 1000000007
#define inv2 500000004
int n,k,p_t=0;
LL res,res1,ans=0;
int p[5002];
LL f[5002],fac[5002],inv[5002],pw[5002];
bool u[5002]={};
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=pw[1]=1;for(int i=1;i<=k;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[k]=Pow(fac[k],mod-2);for(int i=k;i;--i)inv[i-1]=(inv[i]*i)%mod;
	for(int i=2;i<=k;++i)
	{
		if(!u[i])p[++p_t]=i,pw[i]=Pow(i,k);
		for(int j=1;j<=p_t && p[j]<=k/i;++j)
		{
			pw[p[j]*i]=pw[p[j]]*pw[i];
			if(!(i%p[j]))break;
		}
	}
}
inline void solve1()
{
	for(int i=1;i<=n;++i)ans=(ans+((((fac[n]*inv[i])%mod)*inv[n-i])%mod)*pw[i])%mod;
}
inline void solve2()
{
	f[k]=res=1,res1=1;
	for(int i=k-1;i;--i)f[i]=(f[i+1]*inv2+((res*=-inv2)%=mod)*((((res1*=(n-i-1))%=mod)*=((inv[k-i]*fac[k-i-1])%mod))%=mod))%mod;
	res=1,res1=Pow(2,n);
	for(int i=1;i<=k;++i)ans=(ans+((((pw[i]*((((res*=(n-i+1))%=mod)*=((inv[i]*fac[i-1])%mod))%=mod))%mod)*((res1*=inv2)%=mod))%mod)*f[i])%mod;
}
int main()
{
	scanf("%d%d",&n,&k),init();
	if(n<=k)solve1();else solve2();
	return 0&printf("%lld",(ans+mod)%mod);;
}