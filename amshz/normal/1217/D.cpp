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
const int xn = 1e5+10;
const int xm = 2e5+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;
 
int n, m, par[xn];
vector <pii> adj[xn];
bool back[xn], mark[xn], fl1;
 
bool Is_par(int v, int u){
	bool fl2 = false;
	while (v) fl2 = fl2 || (v == u), v = par[v];
	return fl2;
}
 
void DFS(int v){
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i].F, ind = adj[v][i].S;
		if (mark[u]){
			back[ind] = Is_par(v, u);
			fl1 = fl1 || back[ind];
			continue;
		}
		par[u] = v;
		DFS(u);
	}
}
 
 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	int v, u;
	for (int i = 0; i < m; i++){
		cin >> v >> u;
		adj[v].pb({u, i});
	}
	for (int i = 1; i <= n; i++){
		if (mark[i]) continue;
		DFS(i);
	}
	
	if (fl1) cout << 2 << endl;
	else cout << 1 << endl;
	
	for (int i = 0; i < m; i++){
		if (back[i]) cout << 2 << sep;
		else cout << 1 << sep;
	}
	cout << endl;
	
	
	return 0;
}