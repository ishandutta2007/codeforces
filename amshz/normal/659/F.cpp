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
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int n, m, a[xn][xn], sz[xn * xn], par[xn * xn];
int b[xn][xn];
ll k;
vector <pip> vec;
bool mark[xn][xn], vis[xn][xn];

int col(int i, int j){
	return (i - 1) * m + j;
}
bool check(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
}
void DFS(int x, int y, int val){
	vis[x][y] = true;
	-- k;
	if (0 <= k)
		b[x][y] = val;
	for (int i = - 1; i < 2; ++ i)
		for (int j = - 1; j < 2; ++ j)
			if ((i == 0) ^ (j == 0) && check(x + i, y + j) && mark[x + i][y + j] && !vis[x + i][y + j])
				DFS(x + i, y + j, val);
}

int main(){
	fast_io;

	for (int i = 0; i < xn * xn; ++ i)
		sz[i] = 1, par[i] = i;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			cin >> a[i][j], vec.push_back({a[i][j], {i, j}});
	sort(all(vec)), reverse(all(vec));
	for (pip X : vec){
		int x = X.B.A, y = X.B.B, val = X.A;
		mark[x][y] = true;
		if (check(x + 1, y) && mark[x + 1][y])
			merge(col(x, y), col(x + 1, y));
		if (check(x - 1, y) && mark[x - 1][y])
			merge(col(x, y), col(x - 1, y));
		if (check(x, y + 1) && mark[x][y + 1])
			merge(col(x, y), col(x, y + 1));
		if (check(x, y - 1) && mark[x][y - 1])
			merge(col(x, y), col(x, y - 1));
		if (k % val || ll(sz[get_root(col(x, y))]) < k / val)
			continue;
		k /= val;
		DFS(x, y, val);
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j)
				cout << b[i][j] << sep;
			cout << endl;
		}
		return 0;
	}
	cout << "NO" << endl;

	return 0;
}