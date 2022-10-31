# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xm = 1e2+10;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;
 
int n, root = 1;
ll ans[xn], sz[xn], mx;
vector <int> adj[xn];
bool mark[xn];
 
void DFS2(int v){
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		ans[u] = ans[v] - sz[u] - sz[u] + n;
		DFS2(u);
	}
}
 
 
void DFS(int v){
	mark[v] = true;
	sz[v] = 1;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u);
		sz[v] += sz[u];
	}
	ans[root] += sz[v];
}
 
 
 
int main(){
	fast_io;
	
	cin >> n;
	int v, u;
	for (int i = 0; i < n - 1; i++){
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	DFS(root);
	for (int i = 0; i <= n; i++) mark[i] = false;
	DFS2(root);
	
	for (int i = 1; i <= n; i++) mx = max(mx, ans[i]);
	
	cout << mx << endl;
	
	
	return 0;
}