#include <bits/stdc++.h>
using namespace std; //using namespace rel_ops;
#define lll __int128
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1);
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
//inline auto sqr(const auto &x){return x*x;}
//ostream &operator<<(ostream &o,const pair<auto,auto> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
mt19937 rnd(time(0));
const int N=200010;
const int mod=(1?1000000007:998244353);
#define int ll
ll ans=0,n;
map<ll,ll> Map;
int a[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	repeat(i,0,n)cin>>a[i],Map[a[i]-i]+=a[i];
	for(auto i:Map)
		ans=max(ans,i.se);
	cout<<ans<<endl;
	return 0;
}