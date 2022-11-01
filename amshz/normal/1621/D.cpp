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
 
const int xn = 5e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n;
ll a[xn][xn];
ll dist[xn][xn], sum, ans;
priority_queue <pair <ll, pii> > pq;

void upd(int x, int y, int x2, int y2){
	if (x2 < 1)
		x2 = n + n;
	if (y2 < 1)
		y2 = n + n;
	if (n + n < x2)
		x2 = 1;
	if (n + n < y2)
		y2 = 1;
	if (dist[x][y] + a[x][y] < dist[x2][y2]){
		dist[x2][y2] = dist[x][y] + a[x][y];
		pq.push({- dist[x2][y2], {x2, y2}});
	}
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n, sum = 0, ans = INF;
		for (int i = 1; i <= n + n; ++ i){
			for (int j = 1; j <= n + n; ++ j){
				cin >> a[i][j];
				if (n < i && n < j)
					sum += a[i][j];
				dist[i][j] = INF;
				if (i <= n && j <= n)
					dist[i][j] = 0;
				pq.push({- dist[i][j], {i, j}});
			}
		}
		/*
		while (SZ(pq)){
			int x = pq.top().B.A, y = pq.top().B.B;
			pq.pop();
			upd(x, y, x + 1, y);
			upd(x, y, x - 1, y);
			upd(x, y, x, y - 1);
			upd(x, y, x, y + 1);
		}
		for (int i = n + 1; i <= n + n; ++ i)
			for (int j = n + 1; j <= n + n; ++ j)
				ans = min(ans, sum + dist[i][j]);
		*/
		ans = INF;
		ans = min(ans, a[1][n + 1]);
		ans = min(ans, a[1][n + n]);
		ans = min(ans, a[n][n + 1]);
		ans = min(ans, a[n][n + n]);
		ans = min(ans, a[n + 1][1]);
		ans = min(ans, a[n + 1][n]);
		ans = min(ans, a[n + n][1]);
		ans = min(ans, a[n + n][n]);
		ans += sum;
		cout << ans << endl;
	}

	return 0;
}