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

const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, a[xn][xn], ans;
bool mark[xn][xn];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				cin >> a[i][j], mark[i][j] = false;
		ans = 0;
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= n; ++ j){
				vector <pii> vec;
				if (1 < i)
					vec.push_back({i - 1, j});
				if (i < n)
					vec.push_back({i + 1, j});
				if (1 < j)
					vec.push_back({i, j - 1});
				if (j < n)
					vec.push_back({i, j + 1});
				bool flag = false;
				for (pii x : vec)
					flag |= mark[x.A][x.B];
				if (flag)
					continue;
				for (pii x : vec)
					mark[x.A][x.B] = true;
				ans ^= a[i][j];
			}
		}
		cout << ans << endl;
	}

	return 0;
}