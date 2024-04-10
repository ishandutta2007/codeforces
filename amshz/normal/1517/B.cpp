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

const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int qq, n, m, a[xn][xn], mark[xn][xn], ans[xn][xn];
vector <pip> vec;

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n >> m, vec.clear();
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= m; ++ j)
				cin >> a[i][j], mark[i][j] = 0, vec.push_back({a[i][j], {i, j}});
		sort(all(vec));
		for (int i = 0; i < m; ++ i)
			mark[vec[i].B.A][vec[i].B.B] = 1;
		a[0][0] = inf;
		for (int i = 1; i <= m; ++ i){
			pii mn = {0, 0};
			for (int j = 1; j <= n; ++ j)
				for (int k = 1; k <= m; ++ k)
					if (mark[j][k] == 1)
						mn = {j, k};
			mark[mn.A][mn.B] = 2;
			ans[mn.A][i] = a[mn.A][mn.B];
			for (int j = 1; j <= n; ++ j){
				if (j == mn.A)
					continue;
				int last = 0;
				for (int k = 1; k <= m; ++ k)
					if (mark[j][k] == 0)
						last = k;
				mark[j][last] = 2;
				ans[j][i] = a[j][last];
			}
		}
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j)
				cout << ans[i][j] << sep;
			cout << endl;
		}
	}

	return 0;
}