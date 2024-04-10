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
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, q, ans, cnt[xn];

int main(){
	fast_io;

	cin >> n >> m, ans = n;
	while (m --){
		int v, u;
		cin >> v >> u;
		if (u < v)
			swap(v, u);
		ans -= (cnt[v] == 0);
		++ cnt[v];
	}
	cin >> q;
	while (q --){
		int t, v, u;
		cin >> t;
		if (t < 3){
			cin >> v >> u;
			if (u < v)
				swap(v, u);
		}
		if (t == 1){
			ans -= (cnt[v] == 0);
			++ cnt[v];
			ans += (cnt[v] == 0);
		}
		else if (t == 2){
			ans -= (cnt[v] == 0);
			-- cnt[v];
			ans += (cnt[v] == 0);
		}
		else
			cout << ans << endl;
	}

	return 0;
}