# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, dist[xn], par[xm][xn];
int H[xn], part[xn];
pii dp[2][xn], res;
vector <pii> adj[xn], vec;
bool pil[xn];

int LCA(int v, int u){
	if (H[v] > H[u])
		swap(v, u);
	for (int i = xm - 1; i >= 0; -- i)
		if ((1 << i) <= (H[u] - H[v]))
			u = par[i][u];
	if (v == u)
		return v;
	for (int i = xm - 1; i >= 0; -- i)
		if (par[i][v] != par[i][u])
			v = par[i][v], u = par[i][u];
	return par[0][v];
}
void DFS3(int v){
	for (pii u : adj[v]){
		if (u.A == par[0][v])
			continue;
		DFS3(u.A);
		part[v] += part[u.A];
	}
}
void DFS2(int v){
	if (dp[1][v].A < 0 && pil[v])
		dp[1][v] = {0, v};
	vec.clear();
	for (pii u : adj[v])
		if (u.A != par[0][v])
			vec.push_back({dp[0][u.A].A + u.B, dp[0][u.A].B});
	vec.push_back(dp[1][v]);
	sort(all(vec));
	reverse(all(vec));
	int mx = vec[0].A, tmx = 0;
	for (pii x : vec)
		tmx += x.A == mx;
	for (pii u : adj[v]){
		if (u.A == par[0][v])
			continue;
		if (dp[0][u.A].A + u.B < mx || dp[0][u.A].B != vec[0].B)
			dp[1][u.A] = vec[0];
		else
			dp[1][u.A] = vec[1];
		if ((dp[0][u.A].A + u.B == mx && tmx > 2) || (dp[0][u.A].A + u.B < mx && tmx > 1))
			dp[1][u.A].B = v;
		dp[1][u.A].A += u.B;
	}
	for (pii u : adj[v])
		if (u.A != par[0][v])
			DFS2(u.A);
	res = dp[0][v];
	if (dp[1][v].A > res.A)
		res = dp[1][v];
	else if (dp[1][v].A == res.A)
		res.B = v;
	if (!pil[v])
		return;
	int lca = LCA(v, res.B);
	++ part[v];
	++ part[res.B];
	-- part[lca];
	-- part[par[0][lca]];
}
void DFS(int v){
	dp[0][v] = {- inf, v};
	if (pil[v])
		dp[0][v].A = 0;
	for (pii u : adj[v]){
		if (u.A == par[0][v])
			continue;
		par[0][u.A] = v;
		H[u.A] = H[v] + 1;
		dist[u.A] = dist[v] + u.B;
		DFS(u.A);
		if (dp[0][u.A].A + u.B > dp[0][v].A)
			dp[0][v] = {dp[0][u.A].A + u.B, dp[0][u.A].B};
		else if (dp[0][u.A].A + u.B == dp[0][v].A)
			dp[0][v].B = v;
	}
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> m;
	for (int i = 1; i <= m; ++ i){
		int v;
		cin >> v;
		pil[v] = true;
	}
	for (int i = 0; i < n - 1; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
	}
	DFS(1);
	for (int i = 1; i < xm; ++ i)
		for (int v = 1; v <= n; ++ v)
			par[i][v] = par[i - 1][par[i - 1][v]];
	for (int i = 1; i <= n; ++ i)
		dp[1][i] = {- inf, i};
	DFS2(1);
	DFS3(1);
	int mx = 0, tmx = 0;
	for (int i = 1; i <= n; ++ i){
		if (pil[i])
			continue;
		if (part[i] > mx)
			tmx = 0;
		mx = max(mx, part[i]);
		tmx += part[i] == mx;
	}
	cout << mx << sep << tmx << endl;
 
    return 0;
}