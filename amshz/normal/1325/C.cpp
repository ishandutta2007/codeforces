# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 

int n, h[xn], ind[xn], ans[xn], start[xn], S, d[xn];
pii E[xn];
ll sz[xn];
vector <pii> adj[xn], Flor[xn];
vector <int> barg;
map <pii, int> mp;
bool mark[xn], vis[xn], flag = true;


void DFS(int v){
	mark[v] = true;
	int t = 0;
	sz[v] = 1;
	start[v] = S++;
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i].F, id = adj[v][i].S;
		if (mark[u]) continue;
		h[u] = h[v] + 1;
		ind[u] = id;
		DFS(u);
		t ++;
		sz[v] += sz[u];
	}
	if (t == 0 && flag) vis[v] = true;
}
 
 
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
		E[i] = {v, u};
		d[v] ++, d[u] ++;
		mp[{v, u}] = i;
	}
	
	int root = 1;
	for (int i = 2; i <= n; i ++){
		if (d[i] > d[root]) root = i;
	}
	
	DFS(root);
	flag = false;
	int res = 0;
	//sort(E, E + n - 1, cmp);
	
	int mx = 1;
	for (int i = 2; i <= n; i ++){
		if (h[mx] < h[i]) mx = i;
	}
	
	int v = mx;
	
	memset(mark, false, sizeof mark);
	h[v] = 0;
	DFS(v);
	
	int u = v;
	for (int i = 1; i <= n; i ++){
		if (h[u] < h[i]) u = i;
	}
	memset(mark, false, sizeof mark);
	for (int i = 0; i < n - 1; i ++){
		if (v == E[i].F || v == E[i].S || u == E[i].F || u == E[i].S) ans[i] = res ++, mark[i] = true;
	}
	for (int i = 0; i < n - 1; i ++){
		if (mark[i]) continue;
		if (vis[E[i].first] || vis[E[i].second]){
			//cout << E[i].first << sep << E[i].second << endl;
			ans[i] = res ++;
			mark[i] = true;
			break;
		}
	}
	
	for (int i = 0; i < n - 1; i ++){
		if (mark[i]) continue;
		ans[i] = res ++;
	}
	
	for (int i = 0; i < n - 1; i ++) cout << ans[i] << endl;
	
	
	
	return 0;
}