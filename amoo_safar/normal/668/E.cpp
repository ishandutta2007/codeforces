#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> G[Maxn], H[Maxn];
pll exf[Maxn * Maxn];
pll exg[Maxn * Maxn];

ll n, m1, m2;

ll neg(ll a){
	return (a > n ? a - n : a + n);
}

bitset<Maxn> bt, vis[Maxn];
ll mk[Maxn];
vector<ll> top;

void DFS(ll u){
	mk[u] = 1;
	vis[u][u] = 1;
	for(auto adj : G[u]){
		if(!mk[adj]) DFS(adj);
		vis[u] |= vis[adj];
	}
	top.pb(u);
}

int com[Maxn];

void dfs(ll u, ll c){
	bt |= vis[u];
	com[u] = c;
	mk[u] = 1;
	for(auto adj : H[u]){
		if(!mk[adj]) dfs(adj, c);
	}
	vis[u] |= bt;
}


ll ans[Maxn], on[Maxn];

void print(){
	memset(mk, 0, sizeof mk); top.clear();
	for(int i = 1; i <= n + n; i++) if(!mk[i]) DFS(i);
	
	reverse(all(top));
	memset(mk, 0, sizeof mk);
	memset(com, 0, sizeof com);
	int c = 1;
	for(auto x : top){
		if(!mk[x]) dfs(x, x);
	}
	
	bool val = true;
	for(int i = 1; i <= n; i++) val &= (com[i] != com[neg(i)]);
	assert(val);
	
	
	reverse(all(top));
	memset(ans, -1, sizeof ans);
	for(auto x : top){
		if(com[x] != x) continue;
		if(on[com[neg(x)]]) continue;
		on[x] = 1;
	}
	/*
	bool F = true;
	ll u, v;
	for(int i = 0; i < m1; i++){
		u = exf[i].F;
		v = exf[i].S;
		F &= ( (v > n ? 1 - ans[neg(v)] : ans[v]) || (u > n ? 1 - ans[neg(u)] : ans[u]));
	}
	assert(!F);
	bool G = true;
	for(int i = 0; i < m2; i++){
		u = exg[i].F;
		v = exg[i].S;
		G &= ( (v > n ? 1 - ans[neg(v)] : ans[v]) || (u > n ? 1 - ans[neg(u)] : ans[u]));
	}
	//assert(G);
	*/
	for(int i = 1; i <= n; i++) cout << on[com[i]] << ' ';
	exit(0);
}

void solve(){
	for(int i = 0; i < Maxn; i++){
		G[i].clear();
		H[i].clear();
		vis[i] &= vis[0];
	}
	ll u, v;
	for(int i = 0; i < m2; i++){
		u = exg[i].F;
		v = exg[i].S;
		
		G[neg(u)].pb(v);
		G[neg(v)].pb(u);
		H[v].pb(neg(u));
		H[u].pb(neg(v));
	}
	memset(mk, 0, sizeof mk); top.clear();
	for(int i = 1; i <= n + n; i++) if(!mk[i]) DFS(i);
	reverse(all(top));
	
	memset(mk, 0, sizeof mk);
	int c = 1;
	for(auto x : top){
		if(!mk[x]) bt = vis[0], dfs(x, x);
	}
	
	bool val = true;
	for(int i = 1; i <= n; i++) val &= (com[i] != com[neg(i)]);
	if(!val) return ;
	for(int i = 0; i < m1; i++){
		u = exf[i].F;
		v = exf[i].S;
		if(vis[neg(u)][u] || (vis[neg(u)][v] && vis[neg(v)][u])) continue;
		if(vis[neg(v)][v] || (vis[neg(v)][u] && vis[neg(u)][v])) continue;
		
		G[u].pb(neg(u));
		H[neg(u)].pb(u);
		
		G[v].pb(neg(v));
		H[neg(v)].pb(v);
		print();
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m1 >> m2;
	ll u, v;
	for(int i = 0; i < m1; i++){
		cin >> u >> v;
		if(u < 0) u = n - u;
		if(v < 0) v = n - v;
		exf[i] = {u, v};
	}
	
	for(int i = 0; i < m2; i++){
		cin >> u >> v;
		if(u < 0) u = n - u;
		if(v < 0) v = n - v;
		exg[i] = {u, v};
	}
	solve();
	swap(m1, m2);
	swap(exf, exg);
	solve();
	cout << "SIMILAR\n";
	return 0;
}