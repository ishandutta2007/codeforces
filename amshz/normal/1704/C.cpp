// khodaya khodet komak kon
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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, m, a[xn];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 1; i <= m; ++ i)
			cin >> a[i];
		sort(a + 1, a + m + 1);
		a[m + 1] = n + a[1];
		for (int i = 1; i <= m; ++ i)
			a[i] = a[i + 1] - a[i] - 1;
		sort(a + 1, a + m + 1);
		reverse(a + 1, a + m + 1);
		ll ans = 0;
		for (int i = 1; i <= m; ++ i){
			a[i] -= (i - 1) * 4;
			if (1 <= a[i])
				++ ans;
			if (2 <= a[i])
				ans += a[i] - 2;
		}
		ans = n - ans;
		cout << ans << endl;
	}

	return 0;
}