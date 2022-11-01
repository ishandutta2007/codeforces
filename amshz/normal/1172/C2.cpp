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

const int xn = 2e5 + 10;
const int xm = 3e3 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, a[xn], w[xn], sum[2], ans[2], dp[xm][xm], inv[xn];

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		cin >> w[i], sum[a[i]] = (sum[a[i]] + w[i]) % mod;
	for (int i = - xm; i <= xm; ++ i)
		inv[i + xm] = power(sum[0] + sum[1] + i, mod - 2, mod);
	dp[0][0] = 1;
	for (int i = 0; i <= m; ++ i){
		for (int j = 0; i + j <= m && j <= sum[0]; ++ j){
			if (i)
				dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j] * (sum[1] + i - 1) % mod * inv[i - 1 - j + xm] % mod) % mod;
			if (j)
				dp[i][j] = (dp[i][j] + 1LL * dp[i][j - 1] * (sum[0] - j + 1) % mod * inv[i + 1 - j + xm] % mod) % mod;
			if (i + j < m)
				continue;
			ans[1] = (ans[1] + 1LL * (sum[1] + i) * dp[i][j] % mod) % mod;
			ans[0] = (ans[0] + 1LL * (sum[0] - j) * dp[i][j] % mod) % mod;
		}
	}
	for (int i = 0; i < 2; ++ i)
		ans[i] = 1LL * ans[i] * power(sum[i], mod - 2, mod) % mod;
	for (int i = 1; i <= n; ++ i)
		cout << 1LL * w[i] * ans[a[i]] % mod << endl;

	return 0;
}