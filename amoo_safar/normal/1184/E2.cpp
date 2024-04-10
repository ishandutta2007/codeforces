#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> edge;

const int Maxn = 2e5 + 10;
ll Inf = 1e18;
const int Log = 22;
const ll Sqrt = 1000000;
const ll Mod = 998244353LL;

ll p[Maxn];

ll par(ll u){
	if(p[u] == u) return u;
	return p[u] = par(p[u]);
}

bool merge(ll u, ll v){
	u = par(u);
	v = par(v);
	if(u == v) return false;
	p[u] = v;
	return true;
}


vector< pair<ll, pll> > V, VV;

vector<pll> G[Maxn];




ll sp[Maxn][Log], dis[Maxn], sub[Maxn];
ll Mx[Maxn][Log];

 
void DFS(ll u, ll p, ll in = 0){
	sp[u][0] = p; dis[u] = dis[p] + 1;
	Mx[u][0] = in;
	for(int i = 1; i < Log; i++) sp[u][i] = sp[sp[u][i - 1]][i - 1];
	for(int i = 1; i < Log; i++) Mx[u][i] = max( Mx[u][i - 1], Mx[sp[u][i - 1]][i - 1] );
	
	for(auto adj : G[u]){
		if(adj.F == p) continue;
		DFS(adj.F, u, adj.S);
		//sub[u] += sub[adj];
	}
}
 
pll blift(ll u, ll h){
	ll mx = 0;
	for(int i = 0; i < Log; i++){
		if(h & (1ll << i)){
			mx = max(mx, Mx[u][i]);
			u = sp[u][i];
		}
	}
	return {u, mx};
}
 
ll lca(ll u, ll v){
	ll mx = 0;	
	mx = max( {mx, blift(u, max(0ll, dis[u] - dis[v])).S, blift(v, max(0ll, dis[v] - dis[u])).S } );
	u = blift(u, max(0ll, dis[u] - dis[v])).F;
	v = blift(v, max(0ll, dis[v] - dis[u])).F;
	
	if(u == v) return mx;
	
	for(int i = Log - 1; i >= 0; i--){
		if(sp[u][i] != sp[v][i]){
			mx = max({mx, Mx[u][i], Mx[v][i]});
			u = sp[u][i]; v = sp[v][i];
		}
	}
	mx = max({mx, Mx[u][0], Mx[v][0]});
	return mx;
}
 











int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < Maxn; i++) p[i] = i;
	ll n, m;
	cin >> n >>m;	
	ll a, b, u, v, w;
	//cin >> a >> b >> w;
	for(int i = 1; i <= m; i++){
		cin >> v >> u >> w;
		V.pb({w, {u, v}});	
		VV.pb({w, {u, v}});
	}
	sort(all(V));
	
	for(auto X : V){
		if(merge(X.S.F, X.S.S)){
			G[X.S.F].pb({X.S.S, X.F});
			G[X.S.S].pb({X.S.F, X.F});
		} else {
			//VV.pb(X);
			//cerr << X.S.F << " " << X.S.S << ":\n";
		}
		
	}
	
	DFS(1, 0);
	for(int i = 0; i < VV.size(); i++){
		//cerr << "s\n";
		ll W = lca(VV[i].S.F, VV[i].S.S);
		//cerr << W << '\n';
		if(W == VV[i].F) continue;
		cout << W << '\n'; 
	}
	
	return 0;
}