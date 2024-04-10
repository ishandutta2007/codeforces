# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e5 + 10;
const int xm = 4e1 + 10;
const int xlg = 3e1 + 10;
const int SQ = 320;
const int sq = 5e2 + 10;
const int inf = 1e9 + 10;


int n, m, qq, a[xn][2], Par[xn][xlg], root, dp[xn], h[xn], Comp[xn], cnt;
vector <int> adj[xn];
bool mark[xn], cycle[xn], ans;
map <pii, int> mp;


void DFS2(int v){
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS2(u);
		a[v][0] += a[u][0];
		a[v][1] += a[u][1];
	}
	if (cycle[v]) return;
	if (a[v][0] && a[v][1]) ans = true;
}


void DFS(int v, int c, int par){
	mark[v] = true;
	Comp[v] = c;
	dp[v] = h[v];
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (u == par && mp[{v, par}] == 1) continue;
		if (mark[u]){
			dp[v] = min(dp[v], dp[u]);
			continue;
		}
		h[u] = h[v] + 1;
		Par[u][0] = v;
		mp[{v, u}]--;
		DFS(u, c, v);
		dp[v] = min(dp[v], dp[u]);
	}
	if (dp[v] != h[v]) cycle[v] = true;
}

void Build(){
	for (int j = 1; j <= 30; j++){
		for (int i = 1; i <= n; i++){
			if ((1 << j) > h[i]) continue;
			Par[i][j] = Par[Par[i][j - 1]][j - 1];
		}
	}
}

int LCA(int v, int u){
	if (h[u] < h[v]) swap(v, u);
	for (int i = 30; i >= 0; i--){
		if ((1 << i) <= h[u] - h[v]) u = Par[u][i];
	};
	for (int i = 30; i >= 0; i--){
		if (h[v] <= (1 << i)) continue;
		if (Par[v][i] != Par[u][i]) v = Par[v][i], u = Par[u][i];
	}
	if (v == u) return v;
	return Par[v][0];
}
void Solve(int v, int u){
	if (Comp[v] != Comp[u]){
		ans = true;
		return;
	}
	int lca = LCA(v, u);
	a[v][0]++, a[lca][0]--;
	a[u][1]++, a[lca][1]--;
}

 
 
int main(){
	fast_io;
	
	cin >> n >> m >> qq;
	int v, u;
	for (int i = 0; i < m; i++){
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		mp[{v, u}]++;
		mp[{u, v}]++;
	}
	for (int i = 1; i <= n; i++){
		if (mark[i]) continue;
		Par[i][0] = i;
		DFS(i, cnt++, 0);
	}
	Build();
	
	while (qq--){
		cin >> v >> u;
		Solve(v, u);
	}
	
	memset(mark, false, sizeof mark);
	for (int v = 1; v <= n; v++){
		if (mark[v]) continue;
		DFS2(v);
	}
	
	if (ans) cout << "No" << endl;
	else cout << "Yes" << endl;
	
	
	return 0;
}