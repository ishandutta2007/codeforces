#include<bits/stdc++.h>
#define Mx 20
#define LL long long
#define mod 998244353
using namespace std;
int n,m,t;
LL ans,res;
LL fac[22];
int a[50002][22];
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
int main()
{
	fac[0]=1;
	for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	read(n),read(m),ans=(fac[n]*m)%mod;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(a[j][i]);
	for(int i=1;i<=m;++i)
	{
		sort(a[i]+1,a[i]+n+1),t=n+1,res=1;
		for(int j=n;j;--j)
		{
			while(t>1 && a[i][t-1]>j)--t;
			res=(res*(j-t+1))%mod;
		}
		ans=(ans-res)%mod;
	}
	ans=(ans*Pow(fac[n],mod-2))%mod,printf("%lld",(ans+mod)%mod);
	return 0;
}