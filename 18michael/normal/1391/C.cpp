#include<cstdio>
#define LL long long
#define mod 1000000007
LL n;LL fac[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
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
	read(n),fac[0]=1;
	for(LL i=1;i<=n;++i)fac[i]=(fac[i-1]*i)%mod;
	printf("%lld",(fac[n]-pow(2,n-1)+mod)%mod);
	return 0;
}