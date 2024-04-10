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
const int xn = 5e2+10;
const int xm = 3e5+10;
const int SQ = 1000;
const ll inf = 1e9+10;

 
int n, m, t[xn][xn], v, u, w, dist[xn][xn];
vector <pii> adj[xn];
 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = inf;
	for (int i = 0; i < m; i++){
		cin >> v >> u >> w;
		adj[v].pb({u, w});
		adj[u].pb({v, w});
		dist[v][u] = w;
		dist[u][v] = w;
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 0; k < adj[j].size(); k++){
				u = adj[j][k].F, w = adj[j][k].S;
				if (dist[i][u] + w == dist[i][j]) t[i][j]++;
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			int ans = 0;
			for (int k = 1; k <= n; k++){
				if (dist[i][k] + dist[k][j] > dist[i][j]) continue;
				ans += t[i][k];
			}
			cout << ans << sep;
		}
	}
	
	return 0;
}