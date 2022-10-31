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

const int xn = 500 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
int mod = 998244353;
const int base = 257;

int n, m, dp[xn], knap[2][xn][xn], pd[xn], fact[xn], ifact[xn];

int C(int r, int n){
	if (r < 0 || n - r < 0)
		return 0;
	return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main(){
	InTheNameOfGod;

	cin >> n >> m >> mod;
	fact[0] = 1;
	for (int i = 1; i < xn; ++ i)
		fact[i] = 1ll * fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (int i = xn - 2; i >= 0; -- i)
		ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
	pd[0] = 1;
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < i; ++ j){
			dp[i] = (dp[i] + 1ll * dp[j] * pd[i - j - 1] % mod * C(j, i - 1) % mod * (i + 1) % mod) % mod;
			dp[i] = (dp[i] + 1ll * pd[j] * dp[i - j - 1] % mod * C(j, i - 1) % mod * (i + 1) % mod) % mod;
			dp[i] = (dp[i] + 1ll * (C(2, j + 1) + C(2, i - j)) * pd[j] % mod * pd[i - j - 1] % mod * C(j, i - 1) % mod) % mod;
			pd[i] = (pd[i] + 1ll * pd[j] * pd[i - j - 1] % mod * C(j, i - 1) % mod * (i + 1) % mod) % mod;
		}
	}
	knap[0][0][0] = 1;
	for (int i = 1; i <= n; ++ i){
		knap[1][i][i] = dp[i];
		knap[0][i][i] = pd[i];
		knap[0][i][0] = 1;
		for (int j = 1; j <= i; ++ j){
			for (int k = 0; k < i; ++ k){
				int t = i - k - 1, res = 0;
				if (t > j)
					continue;
				res = (res + 1ll * knap[1][k][j - t] * pd[t] % mod) % mod;
				res = (res + 1ll * knap[0][k][j - t] * dp[t] % mod) % mod;
				res = 1ll * res * C(t, j) % mod;
				knap[1][i][j] = (knap[1][i][j] + res) % mod;
				knap[0][i][j] = (knap[0][i][j] + 1ll * knap[0][k][j - t] * pd[t] % mod * C(t, j) % mod) % mod;
			}
		}
	}
	cout << knap[1][n][m] << endl;

	return 0;
}