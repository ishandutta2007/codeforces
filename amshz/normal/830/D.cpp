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
 
const int xn = 4e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;//998244353;
const int base = 257;

int n, dp[2][xn], fact[xn], ifact[xn];

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
	dp[0][0] = 1;
	cin >> n;
	while (n --){
		fill(dp[1], dp[1] + xn, 0);
		for (int i = 0; i < xn; ++ i)
			for (int j = 0; j <= i; ++ j)
				dp[1][i] = (dp[1][i] + 1LL * dp[0][j] * dp[0][i - j] % mod * C(j, i) % mod) % mod;
		for (int i = 1; i < xn; ++ i){
			dp[0][i] = (2LL * dp[1][i] % mod + dp[1][i - 1]) % mod;
			if (i + 1 < xn)
				dp[0][i] = (dp[0][i] + dp[1][i + 1]) % mod;
			dp[0][i] = 1LL * dp[0][i] * i % mod;
			dp[0][i] = (dp[0][i] + dp[1][i]) % mod;
		}
	}
	cout << dp[0][1] << endl;
	
	return 0;
}