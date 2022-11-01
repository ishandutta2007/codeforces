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

const int xn = 8e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, d[xn], m, last, cnt[2][xn];
bool adj[xn][xn], mark[xn];
ll ans;
string S;

int main(){
	fast_io;

	cin >> n;
	for (int v = 1; v <= n; ++ v){
		cin >> S;
		for (int u = 0; u < n; u += 4){
			char c = S[u / 4];
			int k = (c <= '9' ? c - '0' : 10 + (c - 'A'));
			adj[v][u + 1] = ((k & 8) != 0); 
			adj[v][u + 2] = ((k & 4) != 0); 
			adj[v][u + 3] = ((k & 2) != 0); 
			adj[v][u + 4] = ((k & 1) != 0); 
		}
	}
	for (int v = 1; v <= n; ++ v)
		for (int u = 1; u <= n; ++ u)
			d[u] += adj[v][u];
	m = n;
	while (m){
		last = - 1;
		for (int v = 1; v <= n; ++ v)
			if (!mark[v] && (d[v] == m - 1 || !d[v]))
				last = v;
		if (last == - 1)
			break;
		mark[last] = true, -- m;
		for (int v = 1; v <= n; ++ v)
			d[v] -= adj[last][v];
		ans += 1ll * m * (614ll * n + 1);
	}
	if (!m)
		kill(ans);
	last = 0;
	for (int v = 1; v <= n; ++ v)
		if (d[last] < d[v] && !mark[v])
			last = v;
	ans += 3ll * m * (m - 1) / 2;
	for (int v = 1; v <= n; ++ v){
		if (mark[v])
			continue;
		int ted = 0;
		for (int u = 1; u <= n; ++ u)
			if (!mark[u] && (adj[last][v] ^ adj[last][u]))
				ted += adj[v][u];
		++ cnt[adj[last][v]][ted];
	}
	for (int t = 0; t < 2; ++ t)
		for (int i = 0; i < m; ++ i)
			ans += 1ll * cnt[t][i] * (cnt[t][i] - 1) / 2;
	cout << ans << endl;

	return 0;
}