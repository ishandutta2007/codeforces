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
const int xn = 2e5+10;
const int xm = 3e5+10;
const int SQ = 500;
const ll inf = 1e18+10;


struct edge{
	int V, U, ind;
	ll W;
};

int n, m, s, t, dp[xn], h[xn];
vector <pll> adj[xn], ad[xn];
vector <pii> adj2[xn];
ll dis[xn], path, dis2[xn];
edge e[xn];
map <pii, int> mp;
bool mark[xn], boreshi[xn];

void Dijkstra(int start){
	for (int i = 1; i <= n; i++) dis[i] = inf;
	dis[start] = 0;
	set <pll> q;
	for (int i = 1; i <= n; i++) q.insert({dis[i], i});
	while (q.size()){
		int v = q.begin() -> S;
		q.erase(q.begin());
		mark[v] = true;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i].F;
			ll w = adj[v][i].S;
			if (mark[u]) continue;
			q.erase({dis[u], u});
			dis[u] = min(dis[u], dis[v] + w);
			q.insert({dis[u], u});
		}
	}
}
void dijkstra(int start){
	for (int i = 1; i <= n; i++) dis2[i] = inf;
	dis2[start] = 0;
	set <pll> q;
	for (int i = 1; i <= n; i++) q.insert({dis2[i], i});
	while (q.size()){
		int v = q.begin() -> S;
		q.erase(q.begin());
		mark[v] = true;
		for (int i = 0; i < ad[v].size(); i++){
			int u = ad[v][i].F;
			ll w = ad[v][i].S;
			if (mark[u]) continue;
			q.erase({dis2[u], u});
			dis2[u] = min(dis2[u], dis2[v] + w);
			q.insert({dis2[u], u});
		}
	}
}

void DFS(int v, int par, int index){
	mark[v] = true;
	dp[v] = h[v];
	for (int i = 0; i < adj2[v].size(); i++){
		int u = adj2[v][i].F, ind = adj2[v][i].S;
		if (mark[u]){
			if (u != par) dp[v] = min(dp[v], h[u]);
			continue;
		}
		h[u] = h[v] + 1;
		DFS(u, v, ind);
		dp[v] = min(dp[v], dp[u]);
	}
	if (v != s && dp[v] == h[v] && mp[{par, v}] == 1) boreshi[index] = true;
}

 
int main(){
	fast_io;
	
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++){
		int v, u;
		ll w;
		cin >> v >> u >> w;
		adj[v].pb({u, w});
		ad[u].pb({v, w});
		e[i].V = v, e[i].U = u, e[i].W = w, e[i].ind = i;
	}
	Dijkstra(s);
	
	for (int i = 1; i <= n; i++) mark[i] = false;
	dijkstra(t);
	
	
	for (int i = 0; i <= n; i++) mark[i] = false;
	for (int i = 0; i < m; i++){
		int v = e[i].V, u = e[i].U;
		ll w = e[i].W;
		if (dis[t] - dis[v] - dis2[u] == w) adj2[v].pb({u, i}), adj2[u].pb({v, i}), mp[{v, u}]++, mp[{u, v}]++;
	}
	
	DFS(s, 0, 0);
	
	for (int i = 0; i < m; i++){
		int v = e[i].V, u = e[i].U;
		ll w = e[i].W;
		ll nw = dis[t] - dis[v] - dis2[u];
		if (boreshi[i]){
			cout << "YES" << endl;
			continue;
		}
		if (nw > 1){
			cout << "CAN" << sep << w - nw + 1 << endl;
			continue;
		}
		cout << "NO" << endl;
	}
	
	return 0;
}