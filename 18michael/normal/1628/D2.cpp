#include<cstdio>
#define Mx 1000000
#define LL long long
#define mod 1000000007
int Test_num;LL ans;
LL fac[1000002],inv[1000002],pw[1000002],ipw[1000002];
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
	fac[0]=pw[0]=ipw[0]=1;for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=Pow(fac[Mx],mod-2);for(int i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod;
	for(int i=1;i<=Mx;++i)pw[i]=(pw[i-1]<<1)%mod,ipw[i]=(ipw[i-1]*500000004)%mod;
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	init(),scanf("%d",&Test_num);
	for(int n,m,k;Test_num--;)
	{
		scanf("%d%d%d",&n,&m,&k),ans=0;
		if(n==m)ans=n;
		else for(int i=1;i<=m;++i)ans=(ans+((C(n-i-1,m-i)*i)%mod)*ipw[n-i])%mod;
		printf("%lld\n",(ans*k)%mod);
	}
	return 0;
}