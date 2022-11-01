#include <bits/stdc++.h>
using namespace std;
const int N = 305;
const int mod = 998244353;
inline int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
int n, d, f[N][N], g[N][N], ht[N], nf[N], ng[N];
vector<int> G[N];
void dfs(int u, int lst) {
	f[u][0] = 1;
	g[u][0] = 1;
	ht[u] = 0;
	for (int v : G[u]) if (v != lst) {
		dfs(v, u);
		int nht = max(ht[u], ht[v] + 1);
		for (int i = 0; i <= nht; i++) nf[i] = ng[i] = 0;
		for (int i = 0; i <= ht[u]; i++) for (int j = 0; j <= ht[v]; j++) {
			nf[max(i, j + 1)] = (nf[max(i, j + 1)] + 1ll * f[u][i] * f[v][j]) % mod;
			ng[min(i, j + 1)] = (ng[min(i, j + 1)] + 1ll * g[u][i] * g[v][j]) % mod;
			if (i + j + 1 <= d) {
				ng[i] = (ng[i] + 1ll * g[u][i] * f[v][j]) % mod;
				ng[j + 1] = (ng[j + 1] + 1ll * f[u][i] * g[v][j]) % mod;
			} else {
				nf[i] = (nf[i] + 1ll * f[u][i] * g[v][j]) % mod;
				nf[j + 1] = (nf[j + 1] + 1ll * g[u][i] * f[v][j]) % mod;
			}
		}
		for (int i = 0; i <= nht; i++) f[u][i] = nf[i], g[u][i] = ng[i];
		ht[u] = nht;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int pw = qp(2, n), ans = mod - 1;
	for (d = 1; d <= n; d++) {
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		dfs(1, 0);
		int sum = 0;
		for (int i = 0; i <= ht[1]; i++) sum = (sum + g[1][i]) % mod;
		ans = (ans + pw) % mod;
		ans = (ans + mod - sum) % mod;
	}
	ans = 1ll * ans * qp(pw, mod - 2) % mod;
	printf("%d\n", ans);
	return 0;
}