#include <bits/stdc++.h>
using namespace std; using namespace rel_ops;
/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
#define lll __int128
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1);
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cout<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
template<typename _> inline _ sqr(_ x){return x*x;}
ostream &operator<<(ostream &o,const pii &x){return o<<'('<<x.fi<<','<<x.se<<')';}
mt19937 rnd(time(0));
//tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //
const int N=100010;
const int mod=(0?1000000007:998244353);
#define int ll
int a[N];
int f,m,M,n,mm;
void up(int x){
	m=min(m,x);
	M=max(M,x);
	f=1;
}
void solve(){
	cin>>n;
	repeat(i,0,n)cin>>a[i];
	m=inf,M=-inf,f=0,mm=-inf;
	repeat(i,0,n-1){
		if(a[i]==-1 && a[i+1]!=-1)
			up(a[i+1]);
		if(a[i+1]==-1 && a[i]!=-1)
			up(a[i]);
		if(a[i]!=-1 && a[i+1]!=-1)
			mm=max(mm,abs(a[i]-a[i+1]));
	}
	if(!f){cout<<"0 0"<<endl; return;}
	int ans=(m+M)/2;
	cout<<max(M-ans,mm)<<' '<<ans<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while(T--)
		solve();
	return 0;
}