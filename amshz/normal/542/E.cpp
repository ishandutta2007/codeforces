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
const int xm = 5e2+10;
const int SQ = 1000;
const int inf = 1e9+10;

 
int n, m, dis[xn][xn], flag[xn], ans, comp[xn], k, d[xn];
vector <int> adj[xn];
bool mark[xn], fl1, vis[xn];
queue <int> q;

void DFS(int v, int f){
	mark[v] = true;
	comp[v] = k;
	flag[v] = f;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (flag[u] && flag[u] == f) fl1 = true; 
		if (mark[u]) continue;
		DFS(u, 3-f);
	}
}
void BFS(int s){
	dis[s][s] = 0;
	q.push(s);
	while (q.size()){
		int v = q.front();
		q.pop();
		
		for (int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			if (dis[s][u] != -1) continue;
			dis[s][u] = dis[s][v] + 1;
			q.push(u);
		}
	}
}

 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		adj[v].pb(u), adj[u].pb(v);
	}
	for (int i = 1; i <= n; i++){
		if (mark[i]) continue;
		DFS(i, 1);
		k++;
	}
	if (fl1){
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 1; i <= n; i++) mark[i] = false;
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = -1;
	
	for (int i = 1; i <= n; i++) BFS(i);
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[comp[i]] = max(d[comp[i]], dis[i][j]);
	
	for (int i = 1; i <= n; i++){
		if (vis[comp[i]]) continue;
		vis[comp[i]] = true;
		ans += d[comp[i]];
	}
	
	cout << ans << endl;
	
	
	return 0;
}