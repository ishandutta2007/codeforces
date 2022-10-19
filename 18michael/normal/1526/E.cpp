#include<bits/stdc++.h>
#define Mx 400000
#define LL long long
#define mod 998244353
using namespace std;
int n,k,cnt=0;
int sa[200002],rk[200002];
LL fac[400002],inv[400002];
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
inline void init()
{
	fac[0]=1;for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=pow(fac[Mx],mod-2);for(int i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	if(a<b)return 0;
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	init(),read(n),read(k);for(int i=1;i<=n;++i)read(sa[i]),rk[sa[i]]=i;
	for(int i=2;i<=n;++i)cnt+=(rk[sa[i-1]+1]<rk[sa[i]+1]);
	return 0&printf("%lld",C(k+cnt,n));
}