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
const int xn = 1e5+10;
const int xlg = 22;
const int SQ = 233;
const int sq = 1e5+10;
const ll inf = 1e18+10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 

int n, qq, par[xn][xlg], h[xn], Dir[xn];
ll PS[xn][2], ans;
vector <pii> adj[xn];
bool mark[xn];

void DFS2(int v){
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i].F, flag = adj[v][i].S;
		if (mark[u]) continue;
		Dir[u] = flag;
		DFS2(u);
		PS[v][0] += PS[u][0];
		PS[v][1] += PS[u][1];
	}
}


void DFS(int v){
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i].F, flag = adj[v][i].S;
		if (mark[u]) continue;
		par[u][0] = v;
		h[u] = h[v] + 1;
		DFS(u);
	}
}

void Build(){
	for (int j = 1; j <= 30; j++){
		for (int v = 1; v <= n; v++){
			if ((1 << j) > h[v]) continue;
			par[v][j] = par[par[v][j - 1]][j - 1];
		}
	}
}

int LCA(int v, int u){
	if (h[u] < h[v]) swap(v, u);
	for (int i = 30; i >= 0; i--){
		if ((1 << i) <= h[u] - h[v]) u = par[u][i];
	}
	for (int i = 30; i >= 0; i--){
		if ((1 << i) > h[v]) continue;
		if (par[v][i] != par[u][i]) v = par[v][i], u = par[u][i];
	}
	if (v == u) return v;
	return par[v][0];
}

void Solve(int v, int u){
	int lca = LCA(v, u);
	PS[v][0] ++, PS[u][1] ++;
	PS[lca][0] --, PS[lca][1] --;
}
 
 
 
int main(){
	fast_io;
	
	cin >> n;
	int v, u, x;
	for (int i = 0; i < n - 1; i ++){
		cin >> v >> u >> x;
		if (x == 0){
			adj[v].push_back({u, 0});
			adj[u].push_back({v, 0});
		}
		else{
			adj[v].push_back({u, 1});
			adj[u].push_back({v, 2});
		}
	}
	h[1] = 1;
	DFS(1);
	Build();
	cin >> qq;
	u = 1;
	for (int i = 0; i < qq; i ++){
		cin >> v;
		Solve(u, v);
		u = v;
	}
	
	memset(mark, false, sizeof mark);
	DFS2(1);
	
	for (int i = 2; i <= n; i++){
		if (Dir[i] == 1) ans += power(2, PS[i][0]) - 1, ans = (ans + MD) % md;
		else if (Dir[i] == 2) ans += power(2, PS[i][1]) - 1, ans = (ans + MD) % md;
	}
	
	cout << ans << endl;
	
	
	return 0;
}