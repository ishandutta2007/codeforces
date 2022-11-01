# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e5+10;
const int xm = 3e5+10;
const int SQ = 500;
const ll inf = 1e18+10;
 
struct edge{
	int V, U;
	ll W;
};
 
edge E[xm];
int n, m, k, q, par[xn];
ll dis[xn], ans[xm];
pii que[xm];
vector <pll> adj[xn], vec[xn];
vector <int> comp[xn];
vector <edge> yaals;
bool mark[xn];
 
 
int get_root(int v){
	if (v == par[v]) return v;
	return par[v] = get_root(par[v]);
}
void merge(edge e){
	int v = e.V, u = e.U;
	ll w = e.W;
	
	v = get_root(v), u = get_root(u);
	if (v == u) return;
	if (comp[u].size() > comp[v].size()) swap(v, u);
	
	for (int i = 0; i < comp[u].size(); i++){
		int x = comp[u][i];
		for (int j = 0; j < vec[x].size(); j++){
			int y = vec[x][j].F, ind = vec[x][j].S;
			if (get_root(y) == v) ans[ind] = min(ans[ind], w);
		}
		comp[v].pb(x);
	}
	
	par[u] = v;
}
void Dijkstra(){
	for (int i = 1; i <= k; i++) dis[i] = 0, par[i] = i;
	for (int i = k+1; i <= n; i++) dis[i] = inf;
	set <pll> st;
	for (int i = 1; i <= n; i++) st.insert({dis[i], i});
	while (st.size()){
		int v = st.begin() -> S;
		st.erase(st.begin());
		mark[v] = true;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i].F;
			ll w = adj[v][i].S;
			if (mark[u]) continue;
			st.erase({dis[u], u});
			if (dis[v] + w < dis[u]) par[u] = par[v];
			dis[u] = min(dis[u], dis[v] + w);
			st.insert({dis[u], u});
		}
	}
}
bool cmp(edge i, edge j){
	return i.W < j.W;
}
 
 
int main(){
	fast_io;
	
	cin >> n >> m >> k >> q;
	for (int i = 0; i < m; i++) cin >> E[i].V >> E[i].U >> E[i].W, adj[E[i].V].pb({E[i].U, E[i].W}), adj[E[i].U].pb({E[i].V,E[i].W});
	for (int i = 0; i < q; i++) cin >> que[i].F >> que[i].S, vec[que[i].F].pb({que[i].S, i}), vec[que[i].S].pb({que[i].F, i}), ans[i] = inf;
	for (int i = 1; i <= n; i++) par[i] = i;
	
	Dijkstra();
	
	
	for (int i = 0; i < m; i++){
		E[i].W += dis[E[i].V] + dis[E[i].U];
		//if (par[E[i].V] == par[E[i].U]) continue;
		yaals.pb(E[i]);
	}
	for (int i = 1; i <= n; i++) comp[par[i]].pb(i);
	
	sort(yaals.begin(), yaals.end(), cmp);
	
	for (int i = 0; i < yaals.size(); i++){
		merge(yaals[i]);
	}
		
	for (int i = 0; i < q; i++) cout << ans[i] << endl;
	
	
	return 0;
}