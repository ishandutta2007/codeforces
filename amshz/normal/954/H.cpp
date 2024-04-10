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

const int xn = 1e4 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, dp[2][xn], ans[xn], f[2][xn], a[xn], ps[xn];
bool fl;

int ent(int x){
	return 1ll * x * (x - 1) / 2 % mod;
}

int main(){
	InTheNameOfGod;

	cin >> n;
	ps[0] = 1;
	for (int i = 1; i < n; ++ i)
		cin >> a[i], ps[i] = 1ll * ps[i - 1] * a[i] % mod;
	dp[n % 2][0] = f[n % 2][0] = 1;
	for (int i = n - 1; i >= 1; -- i){
		fl = i % 2;
		f[fl][0] = dp[fl][0] = 1;
		for (int j = 1; j <= 2 * (n - i); ++ j){
			dp[fl][j] = 0;
			if (j - 1)
				dp[fl][j] = dp[!fl][j - 2];
			ans[j] = (ans[j] + 1ll * dp[fl][j] * ent(a[i]) % mod * ps[i - 1] % mod) % mod;
			dp[fl][j] = 1ll * dp[fl][j] * a[i] % mod * a[i] % mod;
			if (j > n - i)
				continue;
			f[fl][j] = 1ll * f[!fl][j - 1] * a[i] % mod;
			ans[j] = (ans[j] + 1ll * f[fl][j] * ps[i - 1] % mod) % mod;
			dp[fl][j] = (dp[fl][j] + 2ll * f[fl][j] % mod) % mod;
		}
	}
	for (int i = 1; i < n + n - 1; ++ i)
		cout << ans[i] << sep;
	cout << endl;

	return 0;
}