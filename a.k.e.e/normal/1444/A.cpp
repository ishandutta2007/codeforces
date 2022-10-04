#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
/*const int MOD=;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/

ll p,q;
void solve()
{
	readint(p),readint(q);
	if(p%q){printf("%I64d\n",p);return;}
	ll ans=1;
	for(int i=2;i*i<=q;++i)
	{
		if(q%i)continue;
		int t=1;
		while(!(q%i))q/=i,t*=i;
		ll s;
		for(s=p;!(s%i);s/=i)if(s%t)break;
		chkmax(ans,s);
	}
	if(q>1)
	{
		ll s;
		for(s=p;!(s%q);s/=q);
		chkmax(ans,s);
	}
	printf("%lld\n",ans);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}