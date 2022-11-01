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
const int xn = 1e2+10;
const int xm = 5e2+10;
const int SQ = 1000;
const int inf = 1e9+10;

 
int n, m, dis[xn];
vector <int> adj[xn], d[xn];
ld ans = 1, dp[xn][2];

 
int main(){
	//fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	
	for (int i = 1; i <= n; i++) dis[i] = -1;
	dis[1] = 0;
	queue <int> q;
	q.push(1);
	while (q.size()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			if (dis[u] != -1) continue;
			dis[u] = dis[v] + 1;
			q.push(u);
		}
	}
	
	for (int i = 1; i <= n; i++) d[dis[i]].pb(i);
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < d[i].size(); j++){
			int v = d[i][j];
			for (int k = 0; k < adj[v].size(); k++){
				int u = adj[v][k];
				if (dis[u] == dis[v] - 1) dp[v][0] += dp[u][0];
			}
		}
	}
	dp[n][1] = 1;
	for (int i = n; i >= 0; i--){
		for (int j = 0; j < d[i].size(); j++){
			int v = d[i][j];
			for (int k = 0; k < adj[v].size(); k++){
				int u = adj[v][k];
				if (dis[u] == dis[v] + 1) dp[v][1] += dp[u][1];
			}
		}
	}
	for (int i = 2; i < n; i++){
		ans = max(ans, 2 * dp[i][0] * dp[i][1] / dp[n][0]);
	}
	
	cout << setprecision(7) << ans << endl;
	
	
	return 0;
}