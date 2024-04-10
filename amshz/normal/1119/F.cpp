//khodaya khodet komak kon
# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
# define ordered_set                                     tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2.5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 8e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, c[xn], mark[xn], d[xn];
int par[xn], ord[xn], ptr;
ll dp[xn][2], ans[xn], sum[xn][2];
vector <pii> adj[xn];
vector <int> G[xn];
ordered_set st[xn][2];

bool cmp(int v, int u){ return d[v] > d[u];}
void preDFS(int v){
	st[v][0].insert({- c[v], v});
	st[v][1].insert({0, 0});
	dp[v][0] += c[v], sum[v][0] -= c[v];
	for (pii u : adj[v]){
		if (u.A == par[v])
			continue;
		c[u.A] = u.B, par[u.A] = v;
		preDFS(u.A);
		st[v][0].insert({- c[u.A], u.A});
		st[v][1].insert({- c[u.A], u.A});
		sum[v][0] -= c[u.A], sum[v][1] -= c[u.A];
		dp[v][0] += c[u.A], dp[v][1] += c[u.A];
	}
	dp[v][0] += sum[v][0], dp[v][1] += sum[v][1];
}
void remove(int v, int u, int k){
	pll x = {dp[u][0] - dp[u][1] - c[u], u};
	if (d[v] == k + 1)
		x.A = - c[u];
	if (st[v][0].order_of_key(x) < k)
		sum[v][0] += st[v][0].find_by_order(k) -> A - x.A;
	if (st[v][1].order_of_key(x) < k)
		sum[v][1] += st[v][1].find_by_order(k) -> A - x.A;
	st[v][0].erase(x), st[v][1].erase(x);
}
void add(int v, int u, int k){
	pll x = {dp[u][0] - dp[u][1] - c[u], u};
	st[v][0].insert(x), st[v][1].insert(x);
	if (st[v][0].order_of_key(x) < k)
		sum[v][0] += x.A - (st[v][0].find_by_order(k) -> A);
	if (st[v][1].order_of_key(x) < k)
		sum[v][1] += x.A - (st[v][1].find_by_order(k) -> A);
}
void DFS(int v, int k){
	dp[v][0] -= sum[v][0], dp[v][1] -= sum[v][1];
	sum[v][0] -= st[v][0].find_by_order(k) -> A;
	sum[v][1] -= st[v][1].find_by_order(k) -> A;
	for (int u : G[v]){
		if (u == par[v])
			continue;
		remove(v, u, k);
		if (d[v] > k + 1){
			dp[v][0] -= dp[u][1] + c[u];
			dp[v][1] -= dp[u][1] + c[u];
		}
		else{
			dp[v][0] -= c[u];
			dp[v][1] -= c[u];
		}
		DFS(u, k);
		dp[v][0] += dp[u][1] + c[u];
		dp[v][1] += dp[u][1] + c[u];
		add(v, u, k);
	}
	dp[v][0] += sum[v][0], dp[v][1] += sum[v][1];
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
		++ d[v], ++ d[u];
	}
	preDFS(1);
	for (int i = 1; i <= n; ++ i)
		ord[i] = i;
	sort(ord + 1, ord + n + 1, cmp);
	for (int i = n - 1; i >= 0; -- i){
		while (ptr < n && d[ord[ptr + 1]] > i){
			int v = ord[++ ptr];
			for (pii u : adj[v])
				G[u.A].push_back(v);
		}
		for (int j = 1; j <= n; ++ j){
			int v = ord[j];
			if (d[v] <= i)
				break;
			if (d[par[v]] > i)
				continue;
			DFS(v, i), ans[i] += dp[v][0];
		}
	}
	for (int i = 0; i < n; ++ i)
		cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}