#include<bits/stdc++.h>
// .modulo 
const int mod=998244353;
// .typedef 
typedef long long ll;
typedef unsigned unt;
typedef unsigned long long ull;
typedef double db;
// .lib 
struct pii
{
	int a,b;
	pii():a(0),b(0){}
	pii(int x,int y):a(x),b(y){}
	void read(){scanf("%d%d",&a,&b);}
};
inline int madd(int x,int y)
{return(x+=y)<mod?x:x-mod;}
template<typename Tp>
inline void emin(Tp&x,const Tp&y)
{if(y<x)x=y;}
template<typename Tp>
inline void emax(Tp&x,const Tp&y)
{if(x<y)x=y;}
int qpow(int x,int k)
{int r=1;for(;k;k>>=1,x=x*1ll*x%mod)
if(k&1)r=r*1ll*x%mod;return r;}
// .main 
namespace Solution
{
	int n;
	void solve()
	{
		scanf("%d",&n);
		n++;
		while(n!=1200&&n!=1400&&n!=1600&&n!=1900&&n!=2100
		&&n!=2300&&n!=2400&&n!=2600&&n!=3000)n++;
		printf("%d\n",n);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int T=1;
	//scanf("%d",&T);
	while(T--)Solution::solve();
}