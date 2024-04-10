#include<bits/stdc++.h>
#define Mx 4100
#define LL long long
#define mod 998244353
using namespace std;
int n,m;
LL ans=0,res;
LL fac[4102],inv[4102];
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
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
inline LL calc(int a,int b)
{
	return C(a+b,a);
}
int main()
{
	init(),scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i)
	{
		res=0;
		for(int j=1;j<m;++j)(ans+=((res+=calc(i,j-1)*calc(i-1,m-j))%=mod)*((calc(n-i-1,j)*calc(n-i,m-j-1)*2)%mod))%=mod;
	}
	for(int i=1;i<m;++i)
	{
		res=0;
		for(int j=1;j+1<n;++j)(ans+=((res+=calc(i,j-1)*calc(i-1,n-j))%=mod)*((calc(m-i-1,j+1)*calc(m-i,n-j-2)*2)%mod))%=mod;
	}
	return 0&printf("%lld",ans);
}