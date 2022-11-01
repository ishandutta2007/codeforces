// khodaya khodet komak kon
// Maybe on the Moon
# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;

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
# define ordered_set                                     tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll qq, n, a[xn], ans, ps[xn], ps2[xn];
ordered_set st[2];

void solve(int l, int r, ll dl){
	if (r < l)
		return;
	ps[r + 1] = ps2[r + 1] = ps2[r + 2] = ps2[r] = 0;
	for (int i = r; i >= l; -- i){
		ps[i] = a[i] - ps[i + 1];
		if (i < r)
			ps2[i] = ps2[i + 2] + a[i + 1] * 2;
	}
	ll sum = - a[l], res = 0;
	st[0].clear(), st[1].clear();
	for (int i = l + 1; i <= r; ++ i){
		st[i % 2].insert({- sum - ps[i], i});
		ans += st[i % 2].order_of_key({ps2[i] - dl, 0});
		sum -= a[i];
	}
}

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n, ans = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		solve(1, n, 0);
		solve(2, n, - a[1]);
		solve(1, n - 1, a[n]);
		solve(2, n - 1, a[n] - a[1]);
		ll sum = 0, res = 0;
		for (int i = 1; i <= n; ++ i)
			sum += a[i];
		for (int i = 1; i <= n; ++ i)
			res += a[i], ans += (res > sum - res);
		cout << ans % mod << endl;
	}

	return 0;
}