#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pii;
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
const int MAXN=250005;

int n,MOD,fac[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(MOD);
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	ll ans=0;
	for(int i=1;i<=n;++i)ans=(ans+1ll*(n-i+1)*(n-i+1)%MOD*fac[i]%MOD*fac[n-i]%MOD)%MOD;
	cout<<ans<<endl;
	return 0;
}