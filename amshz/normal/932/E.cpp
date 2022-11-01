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

const int xn = 5e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, k, ans, dp[xn][xn], res = 1;

int main(){
	InTheNameOfGod;

	dp[0][0] = 1;
	for (int i = 1; i < xn; ++ i)
		for (int j = 1; j <= i; ++ j)
			dp[i][j] = 1ll * j * (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
	cin >> n >> k;
	for (int i = 1; i <= min(n, k); ++ i){
		res = 1ll * res * (n - i + 1) % mod * power(i, mod - 2, mod) % mod;
		ans = (ans + 1ll * dp[k][i] * res % mod * power(2, n - i, mod) % mod) % mod;
	}
	cout << ans << endl;

	return 0;
}