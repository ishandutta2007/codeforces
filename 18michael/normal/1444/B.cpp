#include<bits/stdc++.h>
#define Mx 300000
#define LL long long
#define mod 998244353
using namespace std;
int n;LL ans=0;
int a[300002];
LL fac[300002],inv[300002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
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
	fac[0]=1;for(LL i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=Pow(fac[Mx],mod-2);for(LL i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	init(),read(n);for(int i=1;i<=2*n;++i)read(a[i]);
	sort(a+1,a+2*n+1);for(int i=1;i<=n;++i)ans=(ans+a[2*n-i+1]-a[i])%mod;
	return 0&printf("%lld\n",((ans*C(2*n,n))%mod+mod)%mod);
}