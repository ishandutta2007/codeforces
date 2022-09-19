// faz lati nemigire bache shir !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2'000'000'000'000'000'000ll;
const ll Log = 30;

vector<int> G[N];
int mk[N], Tm = 1;
vector<int> vis;
struct DisjointSet {
	int par[N];
	DisjointSet(){
		iota(par, par + N, 0);
	}
	int operator [](int u){
		return Find(u);
	}
	int Find(int u){
		return (par[u] == u ? u : par[u] = Find(par[u]));
	}
	bool Unite(int u, int v){
		u = Find(u); v = Find(v);
		if(u == v) return false;
		par[u] = v;
		return true;
	}
};
DisjointSet al, wei;

void DFS(int u){
	Tm ++;
	for(auto adj : G[u]) mk[adj] = Tm;
	vector<int> vis2, to;
	for(auto adj : vis){
		if(mk[adj] == Tm) vis2.pb(adj);
		else to.pb(adj);
	}
	vis = vis2;

	for(auto adj : to){
		al.Unite(u, adj);
		DFS(adj);
	}
}

vector<pair<ll, pll>> E;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		G[u].pb(v); G[v].pb(u);
		E.pb({w, {u, v}});
	}
	for(int i = 1; i <= n; i++) vis.pb(i);
	int com = 0;
	while(!vis.empty()){
		com ++;
		int bk = vis.back(); vis.pop_back();
		DFS(bk);
	}
	sort(all(E));
	ll ans = 0;
	ll xo = 0;
	for(auto [w, e] : E){
		xo ^= w;
		if(al[e.F] == al[e.S]) continue;
		ans += w;
		al.Unite(e.F, e.S);
		wei.Unite(e.F, e.S);
	}
	ll c0 = (n * (n - 1) / 2ll) - m;
	if(c0 > n - com) return cout << ans << '\n', 0;
	ll mn = xo;
	for(auto [w, e] : E){
		if(wei[e.F] != wei[e.S]) mn = min(mn, w);
	}
	cout << ans + mn << '\n';
	return 0;
}