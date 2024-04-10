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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, cnt[xn], ps[xn];
int res, ans;
vector <pii> vec[xn];
vector <pip> adj[xn];
bool pr[xn];

void DFS(int v, int p = - 1){
	ans = (ans + res) % mod;
	for (pip U : adj[v]){
		int u = U.A, x = U.B.A, y = U.B.B;
		if (p == u)
			continue;
		res = 1ll * res * y % mod;
		res = 1ll * res * power(x, mod - 2, mod) % mod;
		for (pii w : vec[y])
			cnt[w.A] += w.B;
		for (pii w : vec[x]){
			cnt[w.A] -= w.B;
			ps[w.A] = min(ps[w.A], cnt[w.A]);
		}
		DFS(u, v);
		res = 1ll * res * x % mod;
		res = 1ll * res * power(y, mod - 2, mod) % mod;
		for (pii w : vec[y])
			cnt[w.A] -= w.B;
		for (pii w : vec[x])
			cnt[w.A] += w.B;
	}
}

int main(){
	fast_io;

	for (int i = 2; i < xn; ++ i){
		if (pr[i])
			continue;
		for (int j = i; j < xn; j += i){
			int t = 0, jj = j;
			while (jj % i == 0)
				jj /= i, ++ t;
			vec[j].push_back({i, t});
			pr[j] = true;
		}
	}
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			adj[i].clear();
		for (int i = 1; i < n; ++ i){
			int v, u, x, y;
			cin >> v >> u >> x >> y;
			adj[v].push_back({u, {x, y}});
			adj[u].push_back({v, {y, x}});
		}
		fill(cnt, cnt + n + 1, 0);
		fill(ps, ps + n + 1, 0);
		ans = 0, res = 1;
		DFS(1);
		for (int i = 2; i <= n; ++ i)
			ans = 1ll * ans * power(i, - ps[i], mod) % mod;
		cout << ans << endl;
	}

	return 0;
}