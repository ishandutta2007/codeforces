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
int s;
vector <int> g[200010];
int prv[200010],fr[200010];
void dfs(int cur,int ori){
	for (int i:g[cur]){
		if (i==s) continue;
		if (!prv[i]){
			prv[i]=cur;
			fr[i]=ori;
			dfs(i,ori);
		} else if (fr[i]!=ori){
			//found
			cout<<"Possible\n";
			vector <int> v1,v2;
			v1.pb(i);
			while (v1.back()!=s) v1.pb(prv[v1.back()]);
			v2.pb(i); v2.pb(cur);
			while (v2.back()!=s) v2.pb(prv[v2.back()]);
			reverse(v1.begin(),v1.end()); reverse(v2.begin(),v2.end());
			cout<<v1.size()<<'\n'; for (int j:v1) cout<<j<<' '; cout<<'\n';
			cout<<v2.size()<<'\n'; for (int j:v2) cout<<j<<' '; cout<<'\n';
			exit(0);
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m>>s;
	for (int i=0; i<m; i++){
		int u,v; cin>>u>>v;
		g[u].pb(v);
	}
	if (g[s].size()<2){
		cout<<"Impossible\n";
		rt;
	}
	prv[s]=-1;
	for (int i:g[s]){
		if (fr[i]){
			cout<<"Possible\n";
			vector <int> v;
			v.pb(i);
			while (v.back()!=s) v.pb(prv[v.back()]);
			reverse(v.begin(),v.end());
			cout<<v.size()<<'\n'; for (int j:v) cout<<j<<' '; cout<<'\n';
			cout<<"2\n"<<s<<' '<<i<<'\n';
			exit(0);
		}
		prv[i]=s;
		fr[i]=i;
		dfs(i,i);
	}
	cout<<"Impossible\n";
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t=1;
//	cin>>t;
	while (t--) solve();
}