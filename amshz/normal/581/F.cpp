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
 
const int xn = 5e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, root, dp[2][xn][xn], sz[xn];
bool f[xn];
vector <int> adj[xn];

void DFS(int v, int Par = - 1){
	for (int i = 1; i < xn; ++ i)
		dp[0][v][i] = inf;
	if (SZ(adj[v]) == 1){
		swap(dp[0][v][1], dp[0][v][0]);
		sz[v] = 1;
	}
	for (int u : adj[v]){
		if (u == Par)
			continue;
		DFS(u, v);
		sz[v] += sz[u];
		f[v] ^= 1;
		for (int i = 0; i < xn; ++ i)
			dp[f[v]][v][i] = inf;
		for (int i = 0; i <= sz[v]; ++ i)
			for (int j = 0; j <= min(sz[u], i); ++ j)
				dp[f[v]][v][i] = min(dp[f[v]][v][i], dp[!f[v]][v][i - j] + min(dp[f[u]][u][j], dp[f[u]][u][sz[u] - j] + 1));
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	if (n == 2)
		kill(1);
	for (int i = 1; i <= n; ++ i)
		if (SZ(adj[i]) > 1)
			root = i;
	DFS(root);
	cout << dp[f[root]][root][sz[root] / 2] << endl;
	
	return 0;
}