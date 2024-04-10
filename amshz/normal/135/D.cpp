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

int n, m, sz[xn * xn], par[xn * xn], ans;
string S[xn];
set <pii> st;
bool mark[xn][xn], flag;

int col(int x, int y){
	return (x - 1) * m + y;
}
bool is_val(int x, int y){
	if (x < 1 || n < x)
		return false;
	if (y < 1 || m < y)
		return false;
	return true;
}
void DFS(int x, int y){
	mark[x][y] = true;
	if (x == 1 || x == n || y == 1 || y == m)
		flag = false;
	for (int i = - 1; i < 2; ++ i){
		for (int j = - 1; j < 2; ++ j){
			if (!is_val(x + i, y + j))
				continue;
			if (S[x + i][y + j] == '1')
				st.insert({x + i, y + j});
			if (!mark[x + i][y + j])
				DFS(x + i, y + j);
		}
	}
}
int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
bool merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return false;
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	return true;
}

int main(){
	fast_io;

	cin >> n >> m;
	for (int i = 1; i <= n; ++ i){
		cin >> S[i], S[i] = '.' + S[i];
		for (int j = 1; j <= m; ++ j)
			mark[i][j] = S[i][j] - '0';
	}
	for (int i = 1; i < n; ++ i)
		for (int j = 1; j < m; ++ j)
			if (S[i][j] - '0' && S[i + 1][j] - '0' && S[i][j + 1] - '0' && S[i + 1][j + 1] - '0')
				ans = 4;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			if (mark[i][j])
				continue;
			st.clear(), flag = true;
			DFS(i, j);
			for (pii x : st)
				par[col(x.A, x.B)] = col(x.A, x.B), sz[col(x.A, x.B)] = 1;
			int cnt = SZ(st);
			for (pii x : st){
				int d = 0;
				for (int i = - 1; i < 2; ++ i)
					for (int j = - 1; j < 2; ++ j)
						if ((!i || !j) && st.find({x.A + i, x.B + j}) != st.end() && (j || i))
							++ d, cnt -= merge(col(x.A, x.B), col(x.A + i, x.B + j));
				flag &= d == 2;
			}
			flag &= cnt == 1;
			if (flag)
				ans = max(ans, SZ(st));
		}
	}
	cout << ans << endl;

	return 0;
}