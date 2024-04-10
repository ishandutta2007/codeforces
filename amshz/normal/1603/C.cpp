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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e5;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, a[xn], ans;
vector <pii> vec[2][2];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		ans = 0;
		for (int i = 0; i < 2; ++ i)
			vec[0][i].clear();
		for (int i = n; 1 <= i; -- i){
			bool f = i % 2;
			vec[0][f].clear(), vec[1][f].clear();
			for (int j = 1; j <= (a[i] + j - 1) / j; ++ j){
				int x = (a[i] + j - 1) / j;
				vec[0][f].push_back({j, x});
				if (x != j)
					vec[1][f].push_back({x, j});
			}
			reverse(all(vec[1][f]));
			for (pii x : vec[1][f])
				vec[0][f].push_back(x);
			int res = 1, ptr = - 1;
			for (int j = 0; j < SZ(vec[0][f]); ++ j){
				pii x = vec[0][f][j];
				while (ptr + 1 < SZ(vec[0][!f]) && x.B <= a[i + 1] / vec[0][!f][ptr + 1].A)
					++ ptr, res = (res + vec[0][!f][ptr].B) % mod;
				ans = (ans + 1ll * i * res % mod * (x.A - 1) % mod) % mod;
				vec[0][f][j].B = res;
				res = 0;
			}
		}
		cout << ans << endl;
	}

	return 0;
}