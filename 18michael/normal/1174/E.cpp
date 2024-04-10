#include<bits/stdc++.h>
#define Mx 1000000
#define LL long long
#define mod 1000000007
#define eps 1e-9
using namespace std;
int n,t;
LL ans=1,res;
int v[22],v1[22];
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
	if(a<b)return 0;
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
int main()
{
	init(),read(n),t=log(n)/log(2)+eps;
	for(int i=0,j=1;i<=t;++i)v[i]=n/j,v1[i]=n/3/j,j<<=1;
	for(int i=0;i<t;++i)v[i]-=v[i+1],v1[i]-=v1[i+1];
	for(int i=0;i<=t;++i)ans=(ans*fac[v[i]])%mod;
	for(int i=0,j=0;i<=t;++i)ans=(ans*C(v[i]-1+j,j))%mod,j+=v[i];
	for(int i=0;i<t;++i)v[i]-=v1[i];
	for(int k=0,j,k1;k<t;++k)
	{
		res=1,j=k1=0;
		for(int i=0;i<k;++i)res=(res*fac[v[i]+v1[i]])%mod;
		for(int i=k;i<t;++i)res=(res*fac[v1[i]])%mod;
		for(int i=0;i<k;++i)res=(res*C(v[i]+v1[i]-1+j,j))%mod,j+=v[i]+v1[i];
		for(int i=k;i<=t;++i)k1+=v[i];
		res=(((res*C(k1-1+j,j))%mod)*fac[k1])%mod,j+=k1,k1=0;
		for(int i=k;i<t;++i)res=(res*C(v1[i]-1+j,j))%mod,j+=v1[i];
		ans=(ans+res)%mod;
	}
	return 0&printf("%lld\n",ans);
}