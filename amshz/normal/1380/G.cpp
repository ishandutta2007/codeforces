// khodaya khodet komak kon
// Maybe on the Moon
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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 2e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn], inv, ans;

int main(){
	InTheNameOfGod;

	cin >> n, inv = power(n, mod - 2, mod);
	for (int i = 0; i < n; ++ i)
		cin >> a[i];
	sort(a, a + n), reverse(a, a + n);
	for (int i = xn - 2; i >= 0; -- i)
		a[i] = (a[i] + a[i + 1]) % mod;
	for (int k = 1; k <= n; ++ k){
		ans = 0;
		for (int i = k; i < xn; i += k)
			ans = (ans + a[i]) % mod;
		cout << 1ll * ans * inv % mod << sep;
	}
	cout << endl;

	return 0;
}