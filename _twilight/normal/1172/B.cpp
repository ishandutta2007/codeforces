#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;
const int Mod = 998244353;

int n;
int d[N];
int fac[N]; 

/*
void dfs(int p, int fa) {
	sz[p] = 1;
	int br = 0;
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs(e, p);
			sz[p] += sz[e];
			br++;
		}
	}
	f[p] = sz[p] * 1ll * fac[br] % Mod;
	g[p] = (br + 1) * 1ll * fac[br] % Mod;
	for (auto e : G[p]) {
		if (e ^ fa) {
			f[p] = 1ll * f[p] * g[e] % Mod;
			g[p] = 1ll * g[p] * g[e] % Mod;
		}
	}
}
*/

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		++d[u], ++d[v];
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * 1ll * i % Mod;
	}
	int ans = n;
	for (int i = 1; i <= n; i++)
		ans = 1ll * ans * fac[d[i]] % Mod;
	printf("%d\n", ans);
	return 0;
}