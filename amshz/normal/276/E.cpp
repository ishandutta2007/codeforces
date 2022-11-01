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
const int xm = 1e6+10;
const int xk = 1e4+10;
const int SQ = 320;
const int sq = 6e2+10;
const ll inf = 1e18+10;


int dist[xn], dp[xn], start[xn], n, s, c[sq], b[sq], root, ds[xn], a[xn], out[xn], q;
vector <int> adj[xn];
bool mark[xn];
 

void DFS(int v){
	mark[v] = true;
	start[v] = s++;
	dp[v] = dist[v];
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		dist[u] = dist[v] + 1;
		DFS(u);
		dp[v] = max(dp[v], dp[u]);
	}
}
void update1(int l, int r, int x){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r) c[i/SQ] += x, i += SQ;
		else ds[i] += x, i++; 
	}
}
void update2(int l, int r, int x){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r) b[i/SQ] += x, i += SQ;
		else a[i] += x, i++;
	}
}

void Query(int v, int x, int d){
	if (d >= dist[v]) update1(0, d-dist[v], x);//, update2(start[v], start[v], -x);
	if (v == root) return;
	int l = max(start[v]-dist[v]+1, start[v]-d);
	int r = min(start[v]+dp[v]-dist[v], start[v]+d);
	update2(l, r, x);
	if (d > dist[v]){
		l = start[v]-dist[v]+1;
		r = min(start[v]+dp[v]-dist[v], start[v]-dist[v]+d-dist[v]);
		update2(l, r, -x);
	}
}
int get(int v){
	int st = start[v], d = dist[v];
	return a[st] + b[st/SQ] + c[d/SQ] + ds[d];
}

 
int main(){
	fast_io;
	
	cin >> n >> q;
	for (int i = 0; i < n-1; i++){
		int v, u;
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
		out[v]++, out[u]++;
	}
	root = 1;
	for (int i = 2; i <= n; i++) if (out[i] > 2) root = i;
	
	DFS(root);
	
	
	while (q--){
		int type, x, y, z;
		cin >> type;
		if (type){
			cin >> x;
			cout << get(x) << endl;
		}
		else{
			cin >> x >> y >> z;
			Query(x, y, z);
		}
	}
	
	
	return 0;
}