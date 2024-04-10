#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int K = 200 + 5;
const int mod = 1e9 + 7;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
vector <int> e[N];
int n, k, ans, dn, fa[N], rev[N], S[K][K], fc[K];
struct dat {
	int f[K];
	void clear() {memset(f, 0, sizeof(f));}
	dat() {clear();}
	int get() {for(int i = k; ; i--) if(i == -1 || f[i]) return i;}
	friend dat operator + (dat a, dat b) {dat c = a; for(int i = 0; i <= k; i++) add(c.f[i], b.f[i]); return c;}
	friend dat operator - (dat a, dat b) {dat c = a; for(int i = 0; i <= k; i++) add(c.f[i], mod - b.f[i]); return c;}
	friend dat operator * (dat a, dat b) {
		dat c;
		int x = a.get(), y = b.get();
		for(int i = 0; i <= x; i++)
			for(int j = 0; j <= min(k - i, y); j++)
				add(c.f[i + j], 1ll * a.f[i] * b.f[j] % mod);
		return c;
	}
} E, I, f[N], g[N];
void dfs(int id, int f) {fa[id] = f, rev[++dn] = id; for(int it : e[id]) if(it != f) dfs(it, id);}
int main() {
	// freopen("1.in", "r", stdin);
	cin >> n >> k;
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	E.f[0] = I.f[0] = I.f[1] = S[0][0] = 1;
	dfs(1, 0);
	for(int i = n; i; i--) {
		int id = rev[i];
		dat prod;
		prod.f[0] = 1;
		for(int it : e[id]) if(it != fa[id]) prod = prod * (g[it] * I + E), f[id] = f[id] + f[it] - g[it] * I;
		g[id] = g[id] + prod + prod - E;
		f[id] = f[id] + prod + prod - E;
	}
	for(int i = fc[0] = 1; i <= k; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j]) % mod;
	for(int i = 0; i <= k; i++) ans = (ans + 1ll * S[k][i] * fc[i] % mod * f[1].f[i]) % mod;
	cout << ans << endl;
	return 0;
}

/*
2022/4/28
start thinking at ??:??

 f_{i, j}  i  j .
, .
 g_{i, j} , .

, f_{i, j} , g_{i, j} .
.
, 
-  f_i  prod (g_u * I + E).
-  g_i  prod (g_u * I + E).
, 
-  f_i  (sum f_u) +  (g_u * I) .
-  g_i  (sum g_u * I) +  (g_u * I) .
 h_{0 / 1 / 2} .

start coding at 13:38

dfs  =.=, .

finish debugging at 14:52
*/