// khodaya khodet komak kon
// Toxicity
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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, L, R, cnt[2][xn], qq, ans, x, y, f[2];

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n >> L >> R;
		for (int i = 1; i <= n; ++ i)
			cnt[0][i] = cnt[1][i] = 0;
		while (L --){
			int z;
			cin >> z;
			++ cnt[0][z];
		}
		while (R --){
			int z;
			cin >> z;
			++ cnt[1][z];
		}
		x = y = ans = f[0] = f[1] = 0;
		for (int i = 1; i <= n; ++ i){
			int z = min(cnt[0][i], cnt[1][i]);
			cnt[0][i] -= z, cnt[1][i] -= z;
			x += cnt[0][i], y += cnt[1][i];
			f[0] += cnt[0][i] / 2;
			f[1] += cnt[1][i] / 2;
		}
		if (x < y)
			ans += max((x + y) / 2, y - f[1]);
		else
			ans += max((x + y) / 2, x - f[0]);
		cout << ans << endl;
	}

	return 0;
}