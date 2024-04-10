# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e3+10;
const int SQ = 450;
 
int n, m, x, y;
ll dist[xn][xn], dis[xn];
vector <pair <int, ll> > adj[xn];
vector <pair <int, ll> > g[xn];
bool mark[xn];

void dijkstra(int s, ll b, ll c){
	set <pair <ll, int> > q;
	for (int i = 1; i <= n; i++) dist[s][i] = 1e18+10, mark[i] = false;
	dist[s][s] = 0;
	mark[s] = true;
	for (int i = 1; i <= n; i++) q.insert({dist[s][i], i});
	
	while (q.size()){
		set < pair <ll, int> > :: iterator it = q.begin();
		q.erase(it);
		int v = it->S;
		mark[v] = true;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i].F;
			if (mark[u]) continue;
			q.erase({dist[s][u], u});
			dist[s][u] = min(dist[s][u], dist[s][v] + adj[v][i].S);	
			q.insert({dist[s][u], u});	
		}
	}
	for (int i = 1; i <= n; i++){
		if (i != s && dist[s][i] <= b) g[s].pb({i, c});
	}
}

void dij(int s){
	set <pair <ll, int> > q;
	for (int i = 1; i <= n; i++) dis[i] = 1e18+10, mark[i] = false;
	dis[s] = 0;
	mark[s] = true;
	for (int i = 1; i <= n; i++) q.insert({dis[i], i});
	
	while (q.size()){
		set < pair <ll, int> > :: iterator it = q.begin();
		q.erase(it);
		int v = it->S;
		mark[v] = true;
		for (int i = 0; i < g[v].size(); i++){
			int u = g[v][i].F;
			if (mark[u]) continue;
			q.erase({dis[u], u});
			dis[u] = min(dis[u], dis[v] + g[v][i].S);	
			q.insert({dis[u], u});	
		}
	}
}
 
int main(){
	fast_io;
	
	cin >> n >> m >> x >> y;
	for (int i = 0; i < m; i++){
		int v, u;
		ll w;
		cin >> v >> u >> w;
		adj[v].pb({u, w});
		adj[u].pb({v, w});
	}
	
	ll s, t;
	for (int i = 1; i <= n; i++) cin >> s >> t, dijkstra(i, s, t);
	
	dij(x);
	if (dis[y] > 1e15){
		cout << -1 << endl;
		return 0;
	}
	cout << dis[y] << endl;
	
 
	return 0;
}