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
 
int n, a[xn], st[xn], ft[xn], s, t, h[xn], m, qq, sz[xn];
vector <int> adj[xn], Flor[xn];
bool mark[xn];
 
void DFS(int v){
	mark[v] = true;
	st[v] = s++;
	Flor[h[v]].pb(v);
	sz[v] = 1;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		h[u] = h[v] + 1;
		DFS(u);
		sz[v] += sz[u];
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
	}
	DFS(1);
	
	cin >> qq;
	while (qq--){
		int v;
		int u;
		cin >> v >> u;
		int lca = LCA(v, u);
		if (v == u){
			cout << n << endl;
			continue;
		}
		if (h[v] - h[lca] == h[u] - h[lca]){
			int x = find_par(v, h[lca] + 1), y = find_par(u, h[lca] + 1);
			cout << n - sz[x] - sz[y] << endl;
			continue;
		}
		int dis = h[v] + h[u] - 2 * h[lca];
		if (dis % 2){
			cout << 0 << endl;
			continue;
		}
		if (h[v] < h[u]) swap(v, u);
		int x = find_par(v, h[v] - dis / 2);
		int y = find_par(v, h[v] - dis / 2 + 1);
		cout << sz[x] - sz[y] << endl;
	}
	
	
	return 0;
}