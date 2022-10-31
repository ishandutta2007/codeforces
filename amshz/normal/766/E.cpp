//khodaya khodet komak kon
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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn], bit, sz[xn];
ll ans, dp[xn];
vector <int> adj[xn];

void DFS(int v, int p = - 1){
	sz[v] = 1, dp[v] = 0;
	if ((a[v] & (1 << bit)))
		dp[v] = 1;
	for (int u : adj[v]){
		if (u == p)
			continue;
		DFS(u, v);
		ans += (1LL << bit) * dp[u] * (sz[v] - dp[v]);
		ans += (1LL << bit) * dp[v] * (sz[u] - dp[u]);
		sz[v] += sz[u];
		if ((a[v] & (1 << bit)))
			dp[v] += sz[u] - dp[u];
		else
			dp[v] += dp[u];
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], ans += a[i];
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (bit = 0; bit < 20; ++ bit)
		DFS(1);
	cout << ans << endl;
			
	return 0;
}