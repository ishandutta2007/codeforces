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

const int xn = 600 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, m, dist[xn][xn], dp[xn][xn], q, ans;
ppi E[xn * xn];

int main(){
	InTheNameOfGod;

	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (i != j)
				dist[i][j] = INF;
	for (int i = 1; i <= m; ++ i){
		ll v, u, w;
		cin >> v >> u >> w;
		dist[v][u] = min(dist[v][u], w);
		dist[u][v] = min(dist[u][v], w);
		E[i] = {{v, u}, w};
	}
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	cin >> q;
	while (q --){
		int v, u, w;
		cin >> v >> u >> w;
		dp[v][u] = dp[u][v] = w;
	}
	for (int k = 1; k <= n; ++ k){
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= n; ++ j){
				dp[i][j] = max(dp[i][j], dp[k][j] - dist[i][k]);
				dp[j][i] = max(dp[j][i], dp[k][j] - dist[i][k]);
			}
		}
	}
	for (int i = 1; i <= m; ++ i){
		int v = E[i].A.A, u = E[i].A.B, w = E[i].B;
		ans += (dp[v][u] >= w);
	}
	cout << ans << endl;

	return 0;
}