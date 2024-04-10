#include<cstdio>
#define LL long long
#define mod 998244353
LL n;LL fac[1000002],a[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),fac[0]=1,a[0]=0;
	for(LL i=1;i<=n;++i)fac[i]=(fac[i-1]*i)%mod,a[i]=(a[i-1]*i+1)%mod;
	printf("%lld\n",(((n*fac[n])%mod)-a[n]+1+mod)%mod);
	return 0;
}