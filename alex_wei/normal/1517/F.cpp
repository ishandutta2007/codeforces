#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 5;
const int mod = 998244353;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int n, r, ans, sz[N], f[N][N], g[N][N];
vector <int> e[N];
void dfs(int id, int fa) {
	f[id][0] = g[id][0] = sz[id] = 1; // id .
	for(int it : e[id]) {
		if(it == fa) continue;
		dfs(it, id);
		static int ff[N], gg[N];
		memset(ff, 0, sizeof(ff)), memset(gg, 0, sizeof(gg));
		for(int j = 0; j < sz[id]; j++)
			for(int k = 0; k < sz[it]; k++) {
				add(ff[min(j, k + 1)], 1ll * f[id][j] * f[it][k] % mod);
				add(gg[max(j, k + 1)], 1ll * g[id][j] * g[it][k] % mod);
				add(j + k + 1 > r ? gg[k + 1] : ff[j], 1ll * f[id][j] * g[it][k] % mod);
				add(j + k + 1 > r ? gg[j] : ff[k + 1], 1ll * g[id][j] * f[it][k] % mod);
			}
		sz[id] += sz[it];
		memcpy(f[id], ff, sizeof(ff)), memcpy(g[id], gg, sizeof(gg));
	}
}
int main() {
	cin >> n;
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	for(r = 1; r < n; r++) {
		memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g)), dfs(1, 0);
		for(int j = 0; j < n; j++) add(ans, g[1][j]);
	}
	for(int i = 1; i <= n; i++) ans = 1ll * ans * (mod + 1 >> 1) % mod;
	cout << ans << endl;
	return 0;
}

/*
2022/4/30
start thinking at 16:31

 = r .
 = r  - .
,  > r ,  r .
.

 >= r .
 f_{i, j}  i ,  i  j .
 g_{i, j}  i  i  > j  r .
.
 h_i  i .

.

.
.
.
, .
.
?
.
.
.

>= 0 .
< 0  ( 1).
,  n ^ 2.

start coding at 20:21
finish debugging at 20:43

2022/5/3
.
*/