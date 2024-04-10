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
typedef pair <ll, ll>                                    pll;
typedef pair <pii, int>                                  ppi;
typedef pair <pll, ll >                                  ppl;
typedef pair <int, pii>                                  pip;
typedef pair <ll , pll>                                  plp;
typedef pair <pii, pii>                                  ppp;
typedef pair <pll, pll>                                  PPP;
 
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
 
const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;//998244353;
const int base = 257;

ll n, k, dp[2][xn][4], fact[xn], ifact[xn], f[xn], ans;

ll C(ll r, ll n){
	if (r < 0 || n - r < 0)
		return 0;
	return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main(){
	InTheNameOfGod;
	
	fact[0] = 1;
	for (ll i = 1; i < xn; ++ i)
		fact[i] = fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (ll i = xn - 2; i >= 0; -- i)
		ifact[i] = ifact[i + 1] * (i + 1) % mod;
	cin >> n >> k;
	dp[0][0][3] = 1;
	for (int p = 0; p < n; ++ p){
		for (int i = 0; i < xn; ++ i)
			for (int mask = 0; mask < 4; ++ mask)
				dp[1][i][mask] = dp[0][i][mask];
		for (int i = 0; i < xn; ++ i){
			for (int mask = 0; mask < 4; ++ mask){
				bool f1 = (mask & 1), f2 = (mask & 2);
				dp[0][i][mask] = dp[1][i][3];
				if (f1 && i)
					dp[0][i][mask] = (dp[0][i][mask] + dp[1][i - 1][1]) % mod;
				if (f2 && i)
					dp[0][i][mask] = (dp[0][i][mask] + dp[1][i - 1][2]) % mod;
				if (f1 && f2 && i - 1 > 0)
					dp[0][i][mask] = (dp[0][i][mask] + dp[1][i - 2][0]) % mod;
			}
		}
	}
	f[k] = 1;
	for (int i = k; i <= n; ++ i){
		dp[0][i][3] = dp[0][i][3] * fact[n - i] % mod;
		ans = (ans + dp[0][i][3] * f[i] % mod) % mod;
		for (int j = i + 1; j <= n; ++ j)
			f[j] = (f[j] - f[i] * C(i, j) % mod + mod) % mod;
	}
	cout << ans << endl;

	return 0;
}