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
 
const ll md = 1e9+7;
const int xn = 1e5+10;
const int xm = 1e1+10;
const int xk = 3e1+10;
const int SQ = 320;
const int sq = 5e2+10;
const ll inf = 1e18+10;
 
int n, st[xn], ft[xn], s, t, h[xn], m, Par[xn][xk], q, c[xn];
vector <int> adj[xn], Flor[xn], dp[xn][xk], vec, ans, vis[xn];
pii edge[xn];
bool mark[xn];
 
 
 
void DFS(int v){
	mark[v] = true;
	st[v] = s++;
	Flor[h[v]].pb(v);
	for (int i : vis[v])	dp[v][0].push_back(i);
	sort((dp[v][0]).begin(), (dp[v][0]).end());
	dp[v][0].resize(min(int(dp[v][0].size()), 10));
	// cout << v << sep << (vis[v] > 0) << endl;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		h[u] = h[v] + 1;
		Par[u][0] = v;
		DFS(u);
	}
	ft[v] = s++;
}
int find_par(int v, int d){
	int l = 0, r = Flor[d].size(), mid;
	while (r-l > 1){
		mid = (l+r)/2;
		int u = Flor[d][mid];
		if (st[u] <= st[v]) l = mid;
		else r = mid;
	}
	return Flor[d][l];
}
bool check(int v, int u, int d){
	int p = find_par(v, d);
	return (st[p] <= st[u] && ft[p] >= ft[u]);
}
 
int LCA(int v, int u){
	if (h[v] > h[u]) swap(v, u);
	int l = 0, r = h[v]+1, mid;
	while (r-l > 1){
		mid = (l+r)/2;
		if (check(v, u, mid)) l = mid;
		else r = mid;
	}
	return find_par(v, l);
}
void merge(int i, int j, int k){
	int p1 = 0, p2 = 0;
	vec.resize(0);
	while (p1 < dp[i][k].size() || p2 < dp[j][k].size()){
		if (p1 == dp[i][k].size() || (p2 < dp[j][k].size() && dp[j][k][p2] < dp[i][k][p1])){
			vec.pb(dp[j][k][p2]);
			p2++;
			continue;
		}
		else {
			vec.pb(dp[i][k][p1]);
			p1++;
			continue;
		}
	}
	vec.resize(min(10, int(vec.size())));
}
void merg(int i, int k){
	int p1 = 0, p2 = 0;
	vec.resize(0);
	while (p1 < dp[i][k].size() || p2 < ans.size()){
		if (p1 == dp[i][k].size() || (p2 < ans.size() && ans[p2] < dp[i][k][p1])){
			vec.pb(ans[p2]);
			p2++;
			continue;
		}
		else {
			vec.pb(dp[i][k][p1]);
			p1++;
			continue;
		}
	}
	vec.resize(min(10, int(vec.size())));
	ans.resize(0);
	for (int i = 0; i < vec.size(); i++) ans.pb(vec[i]);
}
void Solve(int v, int u, int t){
	int pnt = 30;
	ans.resize(0);
	int par = LCA(v, u);
	//int par2 = Par[par][0];
	//cout << par << endl;
	while (v != par){
		while ((1 << pnt) > h[v] - h[par]) pnt--;
		merg(v, pnt);
		v = Par[v][pnt];
	}
	pnt = 30;
	while (u != par){
		while (h[u] - pow(2, pnt) < h[par]) pnt--;
		merg(u, pnt);
		u = Par[u][pnt];
	}
	merg(par, 0);
	
	cout << min(t, int(ans.size())) << sep;
	//cout << t << endl;
	for (int i = 0; i < min(int(ans.size()), t); i++) cout << ans[i] << sep;
	cout << endl;
	return;
}
 
 
int main(){
	fast_io;
	
	cin >> n >> m >> q;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		adj[v].pb(u), adj[u].pb(v);
	}
	for (int i = 0; i < m; i++) cin >> c[i], vis[c[i]].push_back(i+1);
	h[1] = 1;
	DFS(1);
	for (int j = 1; j <= 30; j++){
		for (int i = 1; i <= n; i++){
			if (h[i] < pow(2, j)) continue;
			Par[i][j] = Par[Par[i][j - 1]][j - 1];
		}
	}
	for (int j = 1; j <= 30; j++){
		for (int i = 1; i <= n; i++){
			if (h[i] < pow(2, j)) continue;
			int p = Par[i][j - 1];
			merge(i, p, j - 1);
			for (int k = 0; k < min(10, int(vec.size())); k++) dp[i][j].pb(vec[k]);
		}
	}
	//for (int i : dp[4][1]) cout << i << sep;
	//cout << endl;
	while (q--){
		int v, u, t;
		cin >> v >> u >> t;
		Solve(v, u, t);
	}
	
	
	return 0;
}