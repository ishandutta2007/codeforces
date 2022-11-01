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

const int xn = 6e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, cnt[2][2];
pii a[xn];
ll ans;

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i].A >> a[i].B;
		a[i].A /= 2, a[i].B /= 2;
		++ cnt[a[i].A % 2][a[i].B % 2];
	}
	for (int x1 = 0; x1 < 2; ++ x1){
		for (int y1 = 0; y1 < 2; ++ y1){
			for (int x2 = 0; x2 < 2; ++ x2){
				for (int y2 = 0; y2 < 2; ++ y2){
					for (int x3 = 0; x3 < 2; ++ x3){
						for (int y3 = 0; y3 < 2; ++ y3){
							int w1 = bool((x1 != x2) | (y1 != y2));
							int w2 = bool((x2 != x3) | (y2 != y3));
							int w3 = bool((x1 != x3) | (y1 != y3));
							/*
							if ((w1 + w2 + w3) % 2)
								continue;
							if (x1 == x2 && y1 == y2 && x1 == x3 && y1 == y3){
								ans += 1ll * cnt[x1][y1]
							}
							if (x1 == x2 && y1 == y2)
								continue;
							if (x2 == x3 && y2 == y3)
								continue;
							if (x1 == x3 && y1 == y3)
								continue;
							*/
							if ((w1 + w2 + w3) % 2 == 0)
								ans += 1ll * cnt[x1][y1] * cnt[x2][y2] * cnt[x3][y3];
						}
					}
				}
			}
		}
	}
	ans -= n;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			if (i == j)
				continue;
			ans -= 3;
		}
	}
	cout << ans / 6 << endl;

	return 0;
}