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

const int xn = 4e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
int mod = 998244353;
const int base = 257;

int n, dp[xn], ps[xn], sum;

int main(){
	fast_io;

	cin >> n >> mod;
	sum = 1;
	for (int i = 1; i <= n; ++ i){
		ps[i] = (ps[i] + ps[i - 1]) % mod;
		dp[i] = (dp[i] + ps[i]) % mod;
		dp[i] = (dp[i] + sum) % mod;
		for (int j = 2; i * j <= n; ++ j){
			ps[i * j] = (ps[i * j] + dp[i]) % mod;
			if (i * j + j <= n)
				ps[i * j + j] = (ps[i * j + j] - dp[i] + mod) % mod;
		}
		if (i != 1)
			sum = (sum + dp[i]) % mod;
	}
	cout << dp[n] << endl;

	return 0;
}