// khodaya khodet komak kon
// Toxicity
# include <bits/stdc++.h>

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

const int xn = 400 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
int mod = 998244353;
const int base = 257;

int n, m, dp[xn][xn], fact[xn], ifact[xn], f[xn], ans;

int C(int r, int n){
	if (r < 0 || n - r < 0)
		return 0;
	return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main(){
	InTheNameOfGod;

	cin >> n >> mod;
	fact[0] = 1;
	for (int i = 1; i < xn; ++ i)
		fact[i] = 1ll * fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (int i = xn - 2; i >= 0; -- i)
		ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= i; ++ j)
			f[i] = (f[i] + C(j - 1, i - 1)) % mod;
	dp[0][0] = 1, ++ n;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j < i; ++ j)
			for (int k = 1; k <= j; ++ k)
				dp[i][j] = (dp[i][j] + 1ll * f[k] * C(k, j) % mod * dp[i - k - 1][j - k] % mod) % mod;
	for (int i = 1; i <= n; ++ i)
		ans = (ans + dp[n][i]) % mod;
	cout << ans << endl;

	return 0;
}