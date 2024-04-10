#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define x first
#define y second
#define pb push_back
#define rt return
#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define dbg(W) cerr<<"[ "<<(#W)<<" is "<<(W)<<" ]\n"
#define dbga(V) cerr<<"[ "<<(#V)<<": ";for(auto&i:V)cout<<i<<' ';cerr<<"]\n"
#define RTE cerr<<__LINE__<<'\n',exit(0)
using namespace std;
using namespace __gnu_pbds;
using pii=pair <int,int>;
using tii=pair <pii,int>;
using rii=pair <int,pii>;
using qii=pair <pii,pii>;
const int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,1,0,-1,-1,1,-1,1};
template <typename T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int mod=1000000007ll;
//const int mod=998244353ll;
mt19937 mt(time(nullptr));
void solve(){
	int n,m;
	cin>>n>>m;
	cout<<n*(m-1)+(m==1?n-1:0ll)<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t=1;
//	cin>>t;
	for (int i=1; i<=t; i++){
		solve();
	}
}