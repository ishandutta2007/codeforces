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

const int xn = 10 + 10;
const int xm = 1e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn], dp[xm], f[xn][xm], ans;

int main(){
	fast_io;

	cin >> n;
	for (int i = 0; i < n; ++ i)
		cin >> a[i];
	for (int i = 0; i < n; ++ i){
		for (int mask = 0; mask < (1 << n); ++ mask){
			f[i][mask] = 1;
			for (int bit = 0; bit < n; ++ bit)
				if ((mask & (1 << bit)))
					f[i][mask] = 1ll * f[i][mask] * a[i] % mod * power(a[i] + a[bit], mod - 2, mod) % mod;
		}
	}
	for (int mask = 1; mask < (1 << n); ++ mask){
		dp[mask] = 1;
		for (int sub = (mask & (mask - 1)); 0 < sub; sub = (mask & (sub - 1))){
			int res = dp[sub];
			for (int bit = 0; bit < n; ++ bit)
				if ((sub & (1 << bit)))
					res = 1ll * res * f[bit][mask ^ sub] % mod;
			dp[mask] = (dp[mask] - res + mod) % mod;
		}
	}
	for (int mask = (1 << n) - 1; mask < (1 << n); ++ mask){
		for (int sub = mask; 0 < sub; sub = (mask & (sub - 1))){
			int res = dp[sub], ted = 0;
			for (int bit = 0; bit < n; ++ bit)
				if ((sub & (1 << bit)))
					res = 1ll * res * f[bit][mask ^ sub] % mod, ++ ted;
			ans = (ans + 1ll * res * ted % mod) % mod;
		}
	}
	cout << ans << endl;

	return 0;
}