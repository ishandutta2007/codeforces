#include <bits/stdc++.h>
using namespace std; using namespace rel_ops;
/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
#define lll __int128
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
typedef double lf; typedef long double llf; const lf err=1e-11;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(_,0,n)cerr<<(a)[_]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto _:a)cerr<<_<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
template<typename _> inline _ sqr(_ x){return x*x;}
mt19937 rnd(time(0));
//tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t; //
const int N=100010;
const int mod=(1?1000000007:998244353);
//#define int ll
int n,a[N],p,now[N],cnt[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n){
		cin>>a[i];
		repeat(j,0,31)
		if(a[i]&(1<<j)){
			cnt[j]++;
		}
	}
	repeat(i,0,n){
		repeat(j,0,31)
		if(a[i]&(1<<j))
		if(cnt[j]==1){
			now[i]+=(1<<j);
		}
	}
	int p=0;
	repeat(i,0,n)
	if(now[i]>now[p])
		p=i;
	swap(a[p],a[0]);
	repeat(i,0,n)cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}