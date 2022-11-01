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
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n;
ll ans;
pii a[xn];
vector <int> vec[2][xn];
set <int> st[xn];

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i].A >> a[i].B;
		vec[0][a[i].A].push_back(i);
		st[a[i].A].insert(a[i].B);
	}
	for (int x = 0; x < xn; ++ x){
		if (sq < SZ(vec[0][x]))
			continue;
		for (int i = 0; i < SZ(vec[0][x]); ++ i){
			for (int j = i + 1; j < SZ(vec[0][x]); ++ j){
				int y1 = vec[0][x][i], y2 = vec[0][x][j];
				y1 = a[y1].B, y2 = a[y2].B;
				int d = abs(y1 - y2);
				if (0 <= x - d && st[x - d].find(y1) != st[x - d].end() && st[x - d].find(y2) != st[x - d].end())
					++ ans;
				if (sq < SZ(vec[0][x + d]) && st[x + d].find(y1) != st[x + d].end() && st[x + d].find(y2) != st[x + d].end())
					++ ans;
			}
		}
	}
	for (int i = 0; i < xn; ++ i)
		st[i].clear();
	for (int i = 1; i <= n; ++ i)
		if (sq < SZ(vec[0][a[i].A]))
			vec[1][a[i].B].push_back(i), st[a[i].B].insert(a[i].A);
	for (int x = 0; x < xn; ++ x){
		if (sq < SZ(vec[1][x]))
			continue;
		for (int i = 0; i < SZ(vec[1][x]); ++ i){
			for (int j = i + 1; j < SZ(vec[1][x]); ++ j){
				int y1 = vec[1][x][i], y2 = vec[1][x][j];
				y1 = a[y1].A, y2 = a[y2].A;
				int d = abs(y1 - y2);
				if (0 <= x - d && st[x - d].find(y1) != st[x - d].end() && st[x - d].find(y2) != st[x - d].end())
					++ ans;
				if (sq < SZ(vec[1][x + d]) && st[x + d].find(y1) != st[x + d].end() && st[x + d].find(y2) != st[x + d].end())
					++ ans;
			}
		}
	}
	cout << ans << endl;

	return 0;
}