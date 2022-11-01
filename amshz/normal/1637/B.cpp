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

const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, a[xn], dp[xn], cnt[xn], res, ans;

void add(int x){
	++ cnt[x];
	while (cnt[res])
		++ res;
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n, ans = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], a[i] = min(a[i], xn - 1);
		for (int l = 1; l <= n; ++ l){
			fill(dp, dp + n + 1, 0);
			for (int r = l; r <= n; ++ r){
				res = 0;
				for (int md = r; l <= md; -- md){
					add(a[md]);
					dp[r] = max(dp[r], dp[md - 1] + res + 1);
				}
				ans += dp[r];
				for (int md = r; l <= md; -- md)
					-- cnt[a[md]];
			}
		}
		cout << ans << endl;
	}

	return 0;
}