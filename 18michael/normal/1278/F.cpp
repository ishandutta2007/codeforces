#include<cstdio>
#define LL long long
#define mod 998244353
int n,m,k,m1,p_t=0;
LL ans=0,res,res1;
int p[664582];
LL f[10000002],inv[10000002],pw[10000002];
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
	f[0]=pw[1]=1;for(int i=1;i<=k;++i)f[i]=(f[i-1]*i)%mod;
	inv[k]=Pow(f[k],mod-2);for(int i=k;i;--i)inv[i-1]=(inv[i]*i)%mod;
	for(int i=2;i<=k;++i)
	{
		if(!pw[i])p[++p_t]=i,pw[i]=Pow(i,k);
		for(int j=1;j<=p_t && p[j]<=k/i;++j)
		{
			pw[p[j]*i]=(pw[p[j]]*pw[i])%mod;
			if(!(i%p[j]))break;
		}
	}
}
inline void solve1()
{
	res=1;
	for(int i=n;i;--i)(ans+=((((((f[n]*inv[i])%mod)*inv[n-i])%mod)*pw[i])%mod)*res)%=mod,(res*=(m-1))%=mod;
}
inline void solve2()
{
	for(int i=1;i<=k;++i)(inv[i]*=f[i-1])%=mod;
	f[k]=res=res1=1;
	for(int i=k-1;i;--i)f[i]=(f[i+1]*(1-m1)+((res*=-m1)%=mod)*((((res1*=(n-i-1))%=mod)*=inv[k-i])%=mod))%mod;
	res=1,res1=Pow(m,n);
	for(int i=1;i<=k;++i)(ans+=((((pw[i]*((((res*=(n-i+1))%=mod)*=inv[i])%=mod))%mod)*((res1*=m1)%=mod))%mod)*f[i])%=mod;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k),m1=Pow(m,mod-2),init();
	if(n<=k)solve1();else solve2();
	return 0&printf("%lld",((ans+mod)*Pow(m1,n))%mod);
}