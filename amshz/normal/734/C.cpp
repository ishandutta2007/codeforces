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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

ll n, m, k, x, s, a[xn], b[xn], c[xn], d[xn];
ll ans = INF;

int main(){
	fast_io;

	cin >> n >> m >> k >> a[0] >> s;
	for (int i = 1; i <= m; ++ i)
		cin >> a[i];
	for (int i = 1; i <= m; ++ i)
		cin >> b[i];
	for (int i = 1; i <= k; ++ i)
		cin >> c[i];
	for (int i = 1; i <= k; ++ i)
		cin >> d[i];
	for (int i = 0; i <= m; ++ i){
		if (s < b[i])
			continue;
		int lb = 0, rb = k + 1;
		while (1 < rb - lb){
			int md = lb + rb >> 1;
			if (d[md] + b[i] <= s)
				lb = md;
			else
				rb = md;
		}
		ans = min(ans, 1ll * (n - c[lb]) * a[i]);
	}
	kill(ans);

	return 0;
}