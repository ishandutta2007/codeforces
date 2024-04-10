#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 200000
#define LL long long
#define mod 998244353
using namespace std;
int n,m;LL ans=0,res=1;
int s[200002],t[200002],cnt[200002]={};
LL fac[200002],inv[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[200002];
	inline void modify(int x,int d)
	{
		while(x<=Mx)sum[x]+=d,x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}S;
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
	read(n),read(m),fac[0]=1;
	for(int i=1;i<=n;++i)read(s[i]),fac[i]=(fac[i-1]*i)%mod,S.modify(s[i],1),++cnt[s[i]];
	inv[n]=Pow(fac[n],mod-2);
	for(int i=n;i;--i)inv[i-1]=(inv[i]*i)%mod;
	res=fac[n];
	for(int i=1;i<=Mx;++i)res=(res*inv[cnt[i]])%mod;
	for(int i=1;i<=m;++i)read(t[i]);
	for(int i=1;i<=m;++i)
	{
		if(i>n)
		{
			ans=(ans+1)%mod;
			break;
		}
		ans=(ans+((((res*inv[n-i+1])%mod)*fac[n-i])%mod)*S.query(t[i]-1))%mod;
		if(!cnt[t[i]])break;
		res=(((((((res*inv[n-i+1])%mod)*fac[n-i])%mod)*fac[cnt[t[i]]])%mod)*inv[cnt[t[i]]-1])%mod,S.modify(t[i],-1),--cnt[t[i]];
	}
	return 0&printf("%lld",ans);
}