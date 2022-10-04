#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005,MOD=998244353;
ll qmi(ll x,ll y)
{
	ll ans=1;
	for(;y;y>>=1,x=x*x%MOD)
		if(y&1)ans=ans*x%MOD;
	return ans;
}

int a[MAXN];
ll n,m,fac[MAXN],k,invf[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);readint(k);
	for(int i=1;i<=n;++i)readint(a[i]);
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%MOD;
	invf[n]=qmi(fac[n],MOD-2);
	for(int i=n-1;i>=0;--i)invf[i]=invf[i+1]*(i+1)%MOD;
	a[0]=a[n];
	for(int i=1;i<=n;++i)
		if(a[i]!=a[i-1])++m;
	ll sum=qmi(k,m);
	for(int i=0;i<=m/2;++i)
		sum=(sum-fac[m]*invf[i]%MOD*invf[i]%MOD*invf[m-2*i]%MOD*qmi(k-2,m-2*i)%MOD+MOD)%MOD;
	printf("%lld\n",sum*qmi(k,n-m)%MOD*qmi(2,MOD-2)%MOD);
	return 0;
}