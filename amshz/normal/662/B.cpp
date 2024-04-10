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
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, cnt;
vector <pair <int, char> > adj[xn];
vector <int> vec;
bool f[2][xn], mark[xn], flag;

void DFS(int v, char c, int id){
	mark[v] = true;
	cnt += f[id][v];
	vec.push_back(v);
	for (pair <int, char> U : adj[v]){
		int u = U.A; char h = U.B;
		if (mark[u]){
			flag |= (bool(h != c) ^ f[id][v] ^ f[id][u]);
			continue;
		}
		f[id][u] = (bool(h != c) ^ f[id][v]);
		DFS(u, c, id);
	}
}
int check(char c, int id){
	memset(mark, false, sizeof mark);
	flag = false;
	for (int v = 1; v <= n; ++ v){
		if (mark[v])
			continue;
		vec.clear();
		cnt = 0;
		DFS(v, c, id);
		if (cnt < SZ(vec) - cnt)
			continue;
		for (int u : vec)
			f[id][u] ^= 1;
	}
	if (flag)
		return inf;
	cnt = 0;
	for (int v = 1; v <= n; ++ v)
		cnt += f[id][v];
	return cnt;
}

int main(){
	fast_io;

	cin >> n >> m;
	while (m --){
		int v, u;
		char c;
		cin >> v >> u >> c;
		adj[v].push_back({u, c});
		adj[u].push_back({v, c});
	}
	int x = check('B', 0);
	int y = check('R', 1);
	if (min(x, y) == inf)
		kill(- 1);
	cout << min(x, y) << endl;
	for (int v = 1; v <= n; ++ v)
		if (f[bool(y < x)][v])
			cout << v << sep;
	cout << endl;

	return 0;
}