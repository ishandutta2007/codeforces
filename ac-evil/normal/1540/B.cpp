#include <bits/stdc++.h>
using std::vector;
typedef long long ll;
const int N = 205, P = 1e9 + 7;
int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = (ll)a * a % P)
		if (b & 1) c = (ll)c * a % P;
	return c;
}
int n, inv[N * 2], fac[N * 2], ifac[N * 2], f[N][N], siz[N], st[N], top = 0, ans = 0;
vector<int> G[N];
int C(int n, int m) {
	assert(n >= m); assert(n >= 0 && m >= 0);
	return (ll)fac[n] * ifac[m] % P * ifac[n - m] % P;
}
void dfs(int u, int fa) {
	siz[u] = 1;
	for (int v : G[u])
		if (v != fa) dfs(v, u), siz[u] += siz[v];
}
void Dfs(int u, int fa) {
	st[++top] = u;
	if (st[1] > st[top]) {
		for (int i = 1; i <= top; i++)
			ans = (ans + (ll)(siz[st[i]] - siz[st[i + 1]]) * f[i - 1][top - i]) % P;
	}
	for (int v : G[u])
		if (v != fa) Dfs(v, u);
	st[top--] = 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	inv[1] = fac[0] = ifac[0] = 1;
	for (int i = 2; i <= n * 2; i++)
		inv[i] = (ll)(P - P / i) * inv[P % i] % P;
	for (int i = 1; i <= n * 2; i++)
		fac[i] = (ll)fac[i - 1] * i % P,
		ifac[i] = (ll)ifac[i - 1] * inv[i] % P;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (i == 0) f[i][j] = 1;
			else if (j == 0) f[i][j] = 0;
			else f[i][j] = (f[i][j - 1] + (ll)C(i + j - 2, i - 1) * qpow(P + 1 >> 1, i + j - 1)) % P;
	for (int i = 1; i <= n; i++)
		dfs(i, 0), Dfs(i, 0);
	ans = (ll)ans * qpow(n, P - 2) % P;
	printf("%d\n", ans);
	return 0;
}