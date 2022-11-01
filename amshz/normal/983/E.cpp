// khodaya khodet komak kon
# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, q, par[xm][xn], H[xn], L[xn], R[xn], S;
pii dp[xn];
vector <int> adj[xn], seg[xn << 2];

pii gmin(pii x, pii y){
	if (x.A != y.A)
		return min(x, y);
	if (H[x.B] < H[y.B])
		return x;
	return y;
}
void preDFS(int v){
	L[v] = S ++, R[v] = S;
	dp[v] = {inf, 0};
	for (int u : adj[v]){
		H[u] = H[v] + 1;
		preDFS(u), R[v] = R[u];
	}
}
int LCA(int v, int u){
	if (H[v] > H[u])
		swap(v, u);
	for (int i = xm - 1; i >= 0; -- i)
		if ((1 << i) <= H[u] - H[v])
			u = par[i][u];
	if (v == u)
		return v;
	for (int i = xm - 1; i >= 0; -- i)
		if (par[i][v] != par[i][u])
			v = par[i][v], u = par[i][u];
	return par[0][v];
}
void DFS(int v){
	for (int u : adj[v])
		DFS(u), dp[v] = gmin(dp[v], dp[u]);
	if (H[dp[v].B] >= H[v])
		dp[v].A = inf;
}
void modify(int id, int l, int r, int pos, int val){
	seg[id].push_back(val);
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
}
void build(int id, int l, int r){
	sort(all(seg[id]));
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
}
bool get(int id, int l, int r, int ql, int qr, int x, int y){
	if (qr <= l || r <= ql || qr <= ql)
		return true;
	if (ql <= l && r <= qr){
		int lb = - 1, rb = SZ(seg[id]);
		while (rb - lb > 1){
			int md = lb + rb >> 1;
			if (seg[id][md] < y)
				lb = md;
			else
				rb = md;
		}
		return (lb < 0 || seg[id][lb] < x);
	}
	int mid = l + r >> 1;
	if (get(lc, l, mid, ql, qr, x, y) && get(rc, mid, r, ql, qr, x, y))
		return true;
	return false;
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 2; i <= n; ++ i){
		cin >> par[0][i];
		adj[par[0][i]].push_back(i);
	}
	H[1] = 1, preDFS(1);
	for (int i = 1; i < xm; ++ i)
		for (int v = 1; v <= n; ++ v)
			par[i][v] = par[i - 1][par[i - 1][v]];
	cin >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		int lca = LCA(v, u);
		dp[v] = min(dp[v], {1, lca});
		dp[u] = min(dp[u], {1, lca});
		modify(1, 0, n, L[v], L[u]);
		modify(1, 0, n, L[u], L[v]);
	}
	DFS(1), build(1, 0, n);
	cin >> q;
	while (q --){
		int v, u;
		cin >> v >> u;
		if (H[v] > H[u])
			swap(v, u);
		int lca = LCA(v, u), ans = 1;
		while (true){
			if (v == lca)
				break;
			if (dp[v].A == inf){
				ans = inf;
				break;
			}
			if (H[dp[v].B] <= H[lca])
				break;
			ans += dp[v].A;
			v = dp[v].B;
		}
		while (true){
			if (u == lca || ans == inf)
				break;
			if (dp[u].A == inf){
				ans = inf;
				break;
			}
			if (H[dp[u].B] <= H[lca])
				break;
			ans += dp[u].A;
			u = dp[u].B;
		}
		if (ans == inf){
			cout << - 1 << endl;
			continue;
		}
		if (L[u] < L[v] || R[v] < R[u])
			ans += get(1, 0, n, L[v], R[v], L[u], R[u]);
		cout << ans << endl;
	}
	
	return 0;
}