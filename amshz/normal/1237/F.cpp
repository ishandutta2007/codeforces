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
 
const int xn = 3.6e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, k, dp[2][xn][xn], fact[xn], ifact[xn], ans, cnt[2];
bool c[xn], r[xn];

int C(int r, int n){
	if (r < 0 || n - r < 0)
		return 0;
	return 1LL * fact[n] % mod * ifact[r] % mod * ifact[n - r] % mod;
}

int main(){
	InTheNameOfGod;
	
	fact[0] = 1;
	for (int i = 1; i < xn; ++ i)
		fact[i] = 1LL * fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (int i = xn - 2; i >= 0; -- i)
		ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
	cin >> n >> m >> k;
	cnt[0] = n, cnt[1] = m;
	while (k --){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		r[x1] = r[x2] = c[y1] = c[y2] = 1;
	}
	dp[0][0][0] = dp[1][0][0] = 1;
	for (int i = 1; i <= n; ++ i){
		cnt[0] -= r[i];
		for (int j = 0; j < xn; ++ j){
			dp[0][i][j] = dp[0][i - 1][j];
			if (!r[i] && !r[i - 1] && i - 1 && j)
				dp[0][i][j] = (dp[0][i][j] + dp[0][i - 2][j - 1]) % mod;
		}
	}
	for (int i = 1; i <= m; ++ i){
		cnt[1] -= c[i];
		for (int j = 0; j < xn; ++ j){
			dp[1][i][j] = dp[1][i - 1][j];
			if (!c[i] && !c[i - 1] && i - 1 && j)
				dp[1][i][j] = (dp[1][i][j] + dp[1][i - 2][j - 1]) % mod;
		}
	}
	for (int i = 0; i < xn; ++ i){
		for (int j = 0; i + i + j <= cnt[0]; ++ j){
			int res = 1LL * dp[0][n][i] * dp[1][m][j] % mod;
			res = 1LL * res * C(j, cnt[0] - i - i) % mod;
			res = 1LL * res * C(i, cnt[1] - j - j) % mod;
			res = 1LL * res * fact[i] % mod;
			res = 1LL * res * fact[j] % mod;
			ans = (ans + res) % mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}