# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e3 + 10;
const int xm = 3e4 + 10;
const int xlg = 2e1 + 10;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) { return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
	

struct edge{
	int V, U, W, mark;
};



int n, m, S, T, a[xn], par[xn], ans = 2e9 + 10, h[xn], dp[xn], id[xn], Id[xn], Par[xn];
//map <pii, int> Mark;
vector <int> adj[xn], vec;
edge E[xm];
bool Mark[xn], Bridge[xn];


void DFS(int v){
	Mark[v] = true;
	dp[v] = h[v];
	for (int i = 0; i < adj[v].size(); i ++){
		int ind = adj[v][i];
		int u = E[ind].V, w = E[ind].W;
		if (u == v) u = E[ind].U;
		if (E[ind].mark) continue;
		E[ind].mark = 1;
		if (Mark[u]){
			dp[v] = min(dp[v], h[u]);
			continue;
		}
		par[u] = v;
		id[u] = ind;
		a[u] = w;
		h[u] = h[v] + 1;
		DFS(u);
		dp[v] = min(dp[v], dp[u]);
	}
	Bridge[v] = (dp[v] == h[v]);
}

void check(int cost, int ind){
	memset(Mark, false, sizeof Mark);
	memset(Bridge, false, sizeof Bridge);
	for (int i = 1; i <= m; i ++) E[i].mark = 0;
	E[ind].mark = 1;
	int v = T;
	DFS(S);
	if (!Mark[T]){
		if (cost < ans){
			vec.clear();
			ans = cost;
			vec.push_back(ind);
		}
		return;
	}
	while (v != S){
		if (Bridge[v]){
			if (a[v] + cost < ans) ans = a[v] + cost, vec.clear(), vec.push_back(ind), vec.push_back(id[v]);
		}
		v = par[v];
	}
}

bool cmp(edge i, edge j){
	return i.W < j.W;
}



int main(){
	fast_io;
	
	
	cin >> n >> m >> S >> T;
	for (int i = 1; i <= m; i ++){
		int v, u, w;
		cin >> v >> u >> w;
		E[i].V = v;
		E[i].U = u;
		E[i].W = w;
		E[i].mark = 0;
		adj[v].push_back(i);
		adj[u].push_back(i);
	}
	//for (int i = 1; i <= n; i ++) sort(adj[i].begin(), adj[i].end());
	
	DFS(S);
	if (!Mark[T]){
		cout << 0 << endl << 0 << endl;
		return 0;
	}
	
	
	check(0, 0);
	
	for (int i = 1; i <= n; i ++) Id[i] = id[i], Par[i] = par[i];
	for (int i = 1; i <= m; i ++) E[i].mark = 0;
	
	int v = T;
	while (v != S){
		int ind = Id[v];
		E[ind].mark = 1;
		check(E[ind].W, ind);
		v = Par[v];
	}
	
	if (ans == 2e9 + 10){
		cout << -1 << endl;
		return 0;
	}
	
	int t = 0;
	for (int i = 0; i < vec.size(); i ++) t += (vec[i] > 0);
	
	cout << ans << endl << t << endl;
	for (int i = 0; i < vec.size(); i ++) if (vec[i]) cout << vec[i] << sep;
	cout << endl;
	
	
	
	return 0;
}