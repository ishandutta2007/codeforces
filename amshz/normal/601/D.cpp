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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod[2] = {998244353, 1000000009};
const int base = 257;

int n, a[xn], pw[2][xn], hsh[2][xn], H[xn], ans[2];
int sz[xn], hvy[xn], ptr, b[xn], cnt[xn], res;
vector <int> adj[xn];
vector <ppi> cprs;
string S;

void preDFS(int v, int p = - 1){
	for (int i = 0; i < 2; ++ i)
		hsh[i][v] = (hsh[i][v] + 1ll * (S[v] - 'a' + 1) * pw[i][H[v]] % mod[i]) % mod[i];
	cprs.push_back({{hsh[0][v], hsh[1][v]}, v});
	sz[v] = 1;
	for (int u : adj[v]){
		if (u == p)
			continue;
		H[u] = H[v] + 1;
		for (int i = 0; i < 2; ++ i)
			hsh[i][u] = hsh[i][v];
		preDFS(u, v);
		if (sz[hvy[v]] < sz[u])
			hvy[v] = u;
		sz[v] += sz[u];
	}
}
void upd(int v, int d, int p = - 1){
	res -= (0 < cnt[b[v]]);
	cnt[b[v]] += d;
	res += (0 < cnt[b[v]]);
	for (int u : adj[v])
		if (u != p)
			upd(u, d, v);
}
void DFS(int v, int p = - 1){
	for (int u : adj[v])
		if (u != p && u != hvy[v])
			DFS(u, v), upd(u, - 1, v);
	if (hvy[v])
		DFS(hvy[v], v);
	for (int u : adj[v])
		if (u != p && u != hvy[v])
			upd(u, 1, v);
	res -= (0 < cnt[b[v]]);
	++ cnt[b[v]];
	res += (0 < cnt[b[v]]);
	a[v] += res;
	if (ans[0] < a[v])
		ans[0] = a[v], ans[1] = 0;
	if (ans[0] == a[v])
		++ ans[1];
}

int main(){
	fast_io;

	for (int i = 0; i < 2; ++ i){
		pw[i][0] = 1;
		for (int j = 1; j < xn; ++ j)
			pw[i][j] = 1ll * pw[i][j - 1] * base % mod[i];
	}
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	cin >> S;
	S = '.' + S;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	preDFS(1);
	sort(all(cprs));
	for (int i = 0; i < SZ(cprs); ++ i){
		if (!i || cprs[i].A != cprs[i - 1].A)
			++ ptr;
		b[cprs[i].B] = ptr;
	}
	DFS(1);
	cout << ans[0] << endl << ans[1] << endl;

	return 0;
}