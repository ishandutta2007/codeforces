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
const int xm = 4e1+10;
const int xk = 1e4+10;
const int SQ = 320;
const int sq = 5e2+10;
const ll inf = 1e18+10;

int n, a[xn], st[xn], ft[xn], s, t, h[xn], m, ans[xn];
vector <int> adj[xn], Flor[xn];
vector <pii> G[xn];
pii edge[xn];
bool mark[xn];

void DFS2(int v, int p){
	for (int i = 0; i < G[v].size(); i++){
		int u = G[v][i].F, ind = G[v][i].S;
		if (u == p) continue;
		DFS2(u, v);
		a[v] += a[u];
		ans[ind] = a[u];
	}
}

void DFS(int v){
	mark[v] = true;
	st[v] = s++;
	Flor[h[v]].pb(v);
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		h[u] = h[v] + 1;
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

 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int v, u;
		cin >> v >> u;
		adj[v].pb(u), adj[u].pb(v);
		edge[i] = {v, u};
	}
	DFS(1);
	
	cin >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		int p = LCA(v, u);
		a[v]++, a[u]++, a[p] -= 2;
	}
	for (int i = 0; i < n-1; i++){
		int v = edge[i].F, u = edge[i].S;
		G[v].pb({u, i}), G[u].pb({v, i});
	}
	DFS2(1, 0);
	
	for (int i = 0; i < n-1; i++) cout << ans[i] << sep;
	cout << endl;
	
	
	return 0;
}