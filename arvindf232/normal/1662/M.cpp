#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define x first
#define y second
#define pb push_back
#define br break
#define ct continue
#define rt return
#define vt vector
#define gt greater
#define prq priority_queue
#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define dbg(W) cerr<<(#W)<<"::"<<(W)<<'\n'
#define dbga(V) cerr<<(#V)<<"::";for(auto&i:V)cout<<i<<' ';cerr<<'\n'
#define RTE cerr<<__LINE__<<'\n',exit(0)
using namespace std;
using namespace __gnu_pbds;
using pii=pair <int,int>;
using tii=pair <pii,int>;
using rii=pair <int,pii>;
using qii=pair <pii,pii>;
const int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,-1,1};
template <typename T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <typename T> using rset=tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1000000007ll;
//const int mod=998244353ll;
mt19937 mt(time(nullptr));
void solve(){
	int n,m;
	cin>>n>>m;
	pii a[m];
	for (int i=0; i<m; i++) cin>>a[i].x>>a[i].y;
	for (int i=0; i<=n; i++){
		bool ok=1;
		for (int j=0; j<m; j++){
			if (a[j].x>i||a[j].y>n-i) ok=0;
		}
		if (ok){
			for (int j=0; j<n; j++){
				if (j<i) cout<<'R';
				else cout<<'W';
			}
			cout<<'\n';
			rt;
		}
	}
	cout<<"IMPOSSIBLE\n";
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t=1;
	cin>>t;
	while (t--) solve();
}