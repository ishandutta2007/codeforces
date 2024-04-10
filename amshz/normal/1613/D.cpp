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

const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, a[xn], cnt[xn], ps[xn], dp[xn], pw[xn], ans;
vector <pii> Q[xn];

int main(){
	fast_io;

	pw[0] = 1;
	for (int i = 1; i < xn; ++ i)
		pw[i] = 2 * pw[i - 1] % mod;
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], Q[i].clear();
		fill(ps, ps + n + 1, 0);
		dp[0] = 1;
		ans = 0;
		for (int i = 1; i <= n; ++ i){
			dp[i] = ps[a[i]];
			if (a[i])
				dp[i] = (dp[i] + ps[a[i] - 1]) % mod;
			if (!a[i])
				dp[i] = (dp[i] + 1) % mod;
			ps[a[i]] = (ps[a[i]] + dp[i]) % mod;
			ans = (ans + dp[i]) % mod;
			if (a[i] + 2 <= n)
				Q[i + 1].push_back({a[i] + 2, i});
		}
		fill(cnt, cnt + n + 1, 0);
		fill(ps, ps + n + 1, 0);
		for (int i = n; 1 <= i; -- i){
			int x = 1;
			if (0 <= a[i] - 2)
				x = pw[cnt[a[i] - 2]];
			ps[a[i]] = (ps[a[i]] + 1ll * pw[cnt[a[i]]] * x % mod) % mod;
			++ cnt[a[i]];
			for (pii y : Q[i])
				ans = (ans + 1ll * dp[y.B] * ps[y.A] % mod) % mod;
		}
		ans = (ans + ps[1]) % mod;
		cout << ans << endl;
	}

	return 0;
}