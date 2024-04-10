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

const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

ll n, a[xn];
ll ans, res, mn;

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int l = 1; l <= n; l += 2){
		res = 0, mn = 0;
		for (int r = l + 1; r <= n; ++ r){
			if (r == l + 1)
				ans += min(a[l], a[r]);
			else if (- mn <= a[l] && l % 2 != r % 2){
				ll x = a[l] + mn;
				ll r2 = res - mn;
				ll y = a[r] - r2;
				if (0 <= y)
					ans += min(x + 1, min(y + 1, a[r]));
			}
			if (l % 2 != r % 2)
				res -= a[r];
			else
				res += a[r];
			mn = min(mn, res);
		}
	}
	cout << ans << endl;

	return 0;
}