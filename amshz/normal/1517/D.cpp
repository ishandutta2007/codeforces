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

const int xn = 5e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, k, a[xn][xn], b[xn][xn], d[xn][xn][11];
priority_queue <ppp> pq;
bool mark[xn][xn][11];

int main(){
	InTheNameOfGod;

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j < m; ++ j)
			cin >> a[i][j];
	for (int i = 1; i < n; ++ i)
		for (int j = 1; j <= m; ++ j)
			cin >> b[i][j];
	if (k % 2){
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j)
				cout << - 1 << sep;
			cout << endl;
		}
		return 0;
	}
	k /= 2;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			for (int t = 0; t < k; ++ t)
				d[i][j][t] = inf;
			pq.push({{0, k}, {i, j}});
		}
	}
	while (SZ(pq)){
		int x = pq.top().B.A;
		int y = pq.top().B.B;
		int t = pq.top().A.B;
		pq.pop();
		if (!t)
			continue;
		if (y - 1 && d[x][y][t] + a[x][y - 1] < d[x][y - 1][t - 1])
			d[x][y - 1][t - 1] = d[x][y][t] + a[x][y - 1], pq.push({{- d[x][y - 1][t - 1], t - 1}, {x, y - 1}});
		if (y < m && d[x][y][t] + a[x][y] < d[x][y + 1][t - 1])
			d[x][y + 1][t - 1] = d[x][y][t] + a[x][y], pq.push({{- d[x][y + 1][t - 1], t - 1}, {x, y + 1}});
		if (x - 1 && d[x][y][t] + b[x - 1][y] < d[x - 1][y][t - 1])
			d[x - 1][y][t - 1] = d[x][y][t] + b[x - 1][y], pq.push({{- d[x - 1][y][t - 1], t - 1}, {x - 1, y}});
		if (x < n && d[x][y][t] + b[x][y] < d[x + 1][y][t - 1])
			d[x + 1][y][t - 1] = d[x][y][t] + b[x][y], pq.push({{- d[x + 1][y][t - 1], t - 1}, {x + 1, y}});
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j)
			cout << d[i][j][0] * 2 << sep;
		cout << endl;
	}

	return 0;
}