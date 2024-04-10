//khodaya khodet komak kon
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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 5e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, pw[xn * xn], dp[xn][xn];

int main(){
	fast_io;

	pw[0] = 1;
	for (int i = 1; i < xn * xn; ++ i)
		pw[i] = 2 * pw[i - 1] % mod;
	cin >> n >> m;
	for (int i = 0; i <= n; ++ i)
		dp[i][0] = 1;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= i; ++ j)
			for (int k = 1; k <= i; ++ k)
				dp[i][j] = (dp[i][j] + 1ll * dp[i - k][j - 1] * (pw[k] - 1 + mod) % mod * pw[k * (i - k)] % mod) % mod;
	cout << dp[n][m] << endl;

	return 0;
}