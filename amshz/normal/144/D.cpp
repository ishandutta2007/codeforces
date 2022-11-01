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
const int xn = 5e5+10;
const int xm = 5e2+10;
const int SQ = 1000;
const int inf = 1e9+10;

struct edge{
	int V, U, W;
};
 
int n, m, s, dis[xn], l, ans;
vector <pii> adj[xn];
bool mark[xn];
edge e[xn];


void dijkstra(int start){
	for (int i = 1; i <= n; i++) dis[i] = inf;
	dis[start] = 0;
	set <pii> q;
	for (int i = 1; i <= n; i++) q.insert({dis[i], i});
	
	while (q.size()){
		int v = q.begin() -> S;
		q.erase(q.begin());
		mark[v] = true;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i].F;
			if (mark[u]) continue;
			q.erase({dis[u], u});
			dis[u] = min(dis[u], dis[v] + adj[v][i].S);
			q.insert({dis[u], u});
		}
	}
}

 
int main(){
	fast_io;
	
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++){
		cin >> e[i].V >> e[i].U >> e[i].W;
		int v = e[i].V, u = e[i].U, w = e[i].W;
		adj[v].pb({u, w});
		adj[u].pb({v, w});
	}
	cin >> l;
	
	dijkstra(s);
	
	for (int i = 1; i <= n; i++) if (dis[i] == l) ans++;
	
	
	for (int v = 1; v <= n; v++){
		if (dis[v] >= l) continue;
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i].F, w = adj[v][i].S;
			if (dis[v] + w > l && dis[v] + w - l + dis[u] >= l && (v > u || dis[v] + w - l + dis[u] != l)) ans++;//, cout << v << sep << u << sep << w << endl;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}