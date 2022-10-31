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
const int xn = 2e6+10;
const int xm = 2e5+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;

int n, m, root;
vector <int> vec[xn];
vector <pair <int, bool> > G[xn];
vector <pii> adj[xn];
bool mark[xn], ans[xn], vis[xn], ansmark[xn], vis2[xn];

void Solve(int v, int u, int ind){
	if (ansmark[ind]) return;
	if (G[ind][0].F == u) ans[ind] = G[ind][0].S;
	else ans[ind] = G[ind][1].S;
	ansmark[ind] = true;
	return;
}


void DFS2(int v){
	vis[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i].F, ind = adj[v][i].S;
		Solve(v, u, ind);
		if (vis[u]) continue;
		DFS2(u);
	}
}

void DFS(int v, int par){
	mark[v] = true;
	if (vis2[v]) root = v;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i].F;
		if (u == par) continue;
		if (mark[u]) root = u;
		else DFS(u, v);
	}
}
 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	int t, x;
	for (int i = 0; i < n; i++){
		cin >> t;
		for (int j = 0; j < t; j++) cin >> x, vec[i].pb(x);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < vec[i].size(); j++){
			x = vec[i][j];
			if (x > 0) G[x].pb({i, true});
			else G[-x].pb({i, false});
		}
	}
	for (int i = 1; i <= m; i++){
		if (G[i].size() == 0) continue;
		if (G[i].size() == 1){
			ans[i] = G[i][0].S;
			vis2[G[i][0].F] = true;
		}
		else{
			if (G[i][0].S == G[i][1].S){
				ans[i] = G[i][0].S;
				vis2[G[i][0].F] = vis2[G[i][1].F] = true;
			}
			else{
				int v = G[i][0].F, u = G[i][1].F;
				adj[v].pb({u, i});
				adj[u].pb({v, i});
			}
		}
	}
	
	for (int i = 0; i < n; i++){
		if (mark[i]) continue;
		root = -1;
		DFS(i, -1);
		if (root == -1){
			cout << "NO" << endl;
			return 0;
		}
		DFS2(root);
	}
	
	cout << "YES" << endl;
	for (int i = 1; i <= m; i++) cout << ans[i];
	cout << endl;
	
	
	
	
	return 0;
}