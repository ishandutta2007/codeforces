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
const int xm = 2e5+1;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;
 
struct edge{
	int V, U, W;
};
 
int n, par[xn], m;
edge e[xn];
ll ans[xn], sz[xn], t[xn];
bool mark[xn];
 
bool cmp(edge i, edge j){
	return i.W < j.W;
}
 
int get_root(int v){
	if (v == par[v]) return v;
	return par[v] = get_root(par[v]);
}
 
void merge(int v, int u, int w){
	if (v == u) return;
	v = get_root(v), u = get_root(u);
	t[w] += sz[v] * sz[u];
	if (sz[u] < sz[v]) swap(v, u);
	par[v] = u;
	sz[u] += sz[v];
}
 
 
 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	int v, u, w;
	for (int i = 0; i < n-1; i++) cin >> e[i].V >> e[i].U >> e[i].W;
	sort(e, e + n - 1, cmp);
	
	for (int i = 1; i <= n; i++) sz[i] = 1, par[i] = i;
	
	for (int i = 0; i < n-1; i++){
		v = e[i].V, u = e[i].U, w = e[i].W;
		merge(v, u, w);
	}
	for (int i = 1; i < xm; i++) ans[i] += t[i] + ans[i - 1];
	
	for (int i = 0; i < m; i++){
		cin >> w;
		cout << ans[w] << sep;
	}
	cout << endl;
	
	
	return 0;
}