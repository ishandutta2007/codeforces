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
const int xm = 30;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

ll n, a[xn], b[xn], c[xn], sum, cnt[xm];

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> b[i], sum += b[i];
	for (int i = 1; i <= n; ++ i)
		cin >> c[i], sum += c[i];
	if (sum % (n + n))
		kill(- 1);
	sum /= n + n;
	for (int i = 1; i <= n; ++ i){
		if ((b[i] + c[i] - sum) % n)
			kill(- 1);
		a[i] = (b[i] + c[i] - sum) / n;
		if (a[i] < 0 || inf < a[i])
			kill(- 1);
		for (int bit = 0; bit < xm; ++ bit)
			if ((a[i] & (1ll << bit)))
				++ cnt[bit];
	}
	for (int i = 1; i <= n; ++ i){
		for (int bit = 0; bit < xm; ++ bit)
			if ((a[i] & (1ll << bit)))
				b[i] -= (1ll << bit) * cnt[bit];
		for (int bit = 0; bit < xm; ++ bit){
			if ((a[i] & (1ll << bit)))
				c[i] -= (1ll << bit) * n;
			else
				c[i] -= (1ll << bit) * cnt[bit];
		}
		if (b[i] || c[i])
			kill(- 1);
	}
	for (int i = 1; i <= n; ++ i)
		cout << a[i] << sep;
	cout << endl;

	return 0;
}