#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 1000000
#define LL long long
#define mod 1000000007
using namespace std;
int n,Test_num;
LL ans=0;
int a[1000002];
LL fac[1000002],inv[1000002];
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
	fac[0]=1;for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=Pow(fac[Mx],mod-2);for(int i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod;
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	init(),read(n);
	for(int i=0;i<=n;++i)
	{
		read(a[i]);
		if(a[i])(ans+=C(i+a[i],a[i]-1))%=mod;
	}
	return 0&printf("%lld",ans);
}