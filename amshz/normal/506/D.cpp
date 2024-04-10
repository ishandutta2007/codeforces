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
 
const int xn = 1e5+10;


int n, m, q;
pii Q[xn];
vector <pii> G[xn];
vector <int> adj[xn], Comp[xn];
map <pii, int> mp;
bool mark[xn];

void DFS(int v, int color){
	mark[v] = true;
	Comp[v].pb(color);
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u, color);
	}
}

 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		G[w].pb({v, u});
	}
	cin >> q;
	for (int i = 0; i < q; i++){
		int v, u;
		cin >> v >> u;
		Q[i] = {v, u};
	}
	int t = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 0; j < G[i].size(); j++){
			int v = G[i][j].F, u = G[i][j].S;
			adj[v].pb(u), adj[u].pb(v);
		}
		for (int j = 0; j < G[i].size(); j++){
			int v = G[i][j].F, u = G[i][j].S;
			if (!mark[v]) DFS(v, t++);
			adj[v].clear(), adj[u].clear();
			mark[v] = mark[u] = false;
		}
	}
	for (int i = 0; i < q; i++){
		int v = Q[i].F, u = Q[i].S;
		if (mp[{v, u}]){
			cout << mp[{v, u}]-1 << endl;
			continue;
		}
		int ans = 1;
		if (Comp[v].size() > Comp[u].size()) swap(v, u);
		for (int j = 0; j < Comp[v].size(); j++){
			int color = Comp[v][j];
			int id = lower_bound(Comp[u].begin(), Comp[u].end(), color) - Comp[u].begin();
			if (id < Comp[u].size() && Comp[u][id] == color) ans++;
		}
		mp[{v, u}] = mp[{u, v}] = ans;
		cout << ans-1 << endl;
	}
	
	
	return 0;
}