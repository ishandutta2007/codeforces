# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const ll MD = md * 100;
const int xn = 2e3 + 10;
const int xm = 4e6 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int n, m, Root = 1, ans, Par[xn], sz[xn], par[xn], a[xn], SZ[xn], t;
vector <int> adj[xn], G[xn], bach;
pii E[xm];
bool Mark[xn], dp[xn][xn];


void DFS2(int v){
	Mark[v] = true;
	SZ[v] = sz[v];
	if (par[v] == Root) bach.push_back(v);
	for (int i = 0; i < G[v].size(); i ++){
		int u = G[v][i];
		if (Mark[u]) continue;
		par[u] = v;
		DFS2(u);
		SZ[v] += SZ[u];
	}
	t += sz[v] * SZ[v];
}


void Solve(){
	memset(par, 0, sizeof par);
	memset(Mark, false, sizeof Mark);
	memset(a, 0, sizeof a);
	memset(SZ, 0, sizeof SZ);
	memset(dp, false, sizeof dp);
	bach.clear();
	t = 0;
	
	DFS2(Root);
	ans = max(ans, t);
	for (int i = 0; i < bach.size(); i ++){
		int v = bach[i];
		if (i == 0){
			dp[i][0] = true;
			dp[i][SZ[v]] = true;
			continue;
		}
		for (int j = 0; j < n; j ++){
			if (dp[i - 1][j]) dp[i][j] = true;
			if (SZ[v] <= j && dp[i - 1][j - SZ[v]]) dp[i][j] = true;
		}
	}
	int pnt = bach.size() - 1;
	if (pnt == -1) return;
	for (int i = 0; i < n; i ++){
		if (!dp[pnt][i]) continue;
		ans = max(ans, t + i  * (SZ[Root] - sz[Root] - i));
	}
}


int get_root(int v){
	if (v == Par[v]) return v;
	return Par[v] = get_root(Par[v]);
}
void Merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u) return;
	swap(v, u);
	Par[u] = v;
	sz[v] += sz[u];
}

void DFS(int v){
	Mark[v] = true;
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		if (u == par[v]) continue;
		if (Mark[u]){
			int x = v;
			while (get_root(x) != get_root(u)) x = get_root(x), Merge(x, par[x]);
			continue;
		}
		par[u] = v;
		DFS(u);
	}
}



 
int main(){
	fast_io;
	
	
	cin >> n >> m;
	for (int i = 0; i < m; i ++){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		E[i] = {v, u};
	}
	
	for (int i = 1; i <= n; i ++) Par[i] = i, sz[i] = 1;
	
	DFS(Root);
	
	for (int i = 0; i < m; i ++){
		int v = E[i].F, u = E[i].S;
		v = get_root(v);
		u = get_root(u);
		if (v == u) continue;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	
	for (int v = 1; v <= n; v ++){
		if (get_root(v) != v) continue;
		Root = v;
		Solve();
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}