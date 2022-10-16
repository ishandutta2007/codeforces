//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
#define rsz(x, n) x.resize(n)
#define clr(x) x.clear()
class SCC
{
public:
  int n, cnt; // cnt -> number of scc's formed
  vector<vector<int>> g, rg, sg, comp; // sg -> dag with all nodes compressed.
  vector<int> scc, order;
  vector<bool> vis;
  void reset(){
    clr(g), clr(rg), clr(sg), clr(comp), clr(scc), clr(order), clr(vis);
  }
  void init(int _n)
  {
    reset();
    n = _n, cnt = 0;
    _n += 2;
    rsz(g, _n), rsz(rg, _n), rsz(sg, _n), rsz(comp, _n);
    scc.resize(_n, 0);
    vis.resize(_n, 0);
  }
  void add(int u,int v){
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  void compute(){
    fr(i, 1, n)
      if(!vis[i]) dfs1(i);
    fill(all(vis), 0);
    for(int i = n - 1; i >= 0; i--)
      if(!vis[order[i]])
        dfs2(order[i],++cnt);
  }
  void dfs1(int u){
    vis[u] = 1;
    for(int v: g[u])
      if(!vis[v]) dfs1(v);
    order.pb(u);
  }
  void dfs2(int u,int c){
    vis[u] = 1;
    scc[u] = c;
    comp[c].pb(u);
    for(int v: rg[u]){
      if(!vis[v])
        dfs2(v,c);
      if(vis[v] && c != scc[v])
        sg[scc[v]].pb(c);
    }
  }
};
void solve() {
	int n;
	cin>>n;
	SCC G;
	G.init(n);
	fr(i,1,n) {
		int te;
		cin>>te;
		G.add(i, te);
	}
	G.compute();
	vi sizes;
	for(auto &i: G.comp) {
		sizes.pb(i.size());
	}
	sort(all(sizes));
	if(sizes.size()==1) {
		cout<<sizes[0]*sizes[0]<<endl;
	} else {
		int ans=0;
		for(int i=0; i+2<sizes.size(); i++) {
			ans+=sizes[i]*sizes[i];
		}
		ans+=(sizes[sz(sizes)-2]+sizes[sz(sizes)-1])*(sizes[sz(sizes)-2]+sizes[sz(sizes)-1]);
		cout<<ans<<endl;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}