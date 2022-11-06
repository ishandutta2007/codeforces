#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using std::vector; using std::pair;
typedef long long ll;
const int N = 2e5 + 5, P = 998244353;
int n, m, k, x[N], y[N];
vector<pair<int, int>> G[N * 18];
ll dis[N * 18]; int vis[N * 18];
void dijk(int s, int ban) {
	std::priority_queue<std::pair<ll, int>> Q;
	std::fill(vis + 1, vis + ban + 1, 0);
	std::fill(dis + 1, dis + ban + 1, 1e18);
	dis[s] = 0; Q.push({0, s});
	while (!Q.empty()) {
		int u = Q.top().se; Q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto x : G[u]) {
			int v = x.fi, w = x.se;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				Q.push({-dis[v], v});
			}
		}
	}
}
int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P)
		if (b & 1) c = 1ll * c * a % P;
	return c;
}
int main() {
	scanf("%d%d", &n, &m); k = log2(n);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		int u = x[i], v = y[i];
		for (int j = 0; j <= k; j++)
			if (j & 1) G[v + n * j].pb({u + n * j, 1}); else G[u + n * j].pb({v + n * j, 1});
	}
	for (int i = 0; i < k; i++)
		for (int j = 1; j <= n; j++)
			G[j + n * i].pb({j + n * (i + 1), 1 << i});
	dijk(1, n * (k + 1));
	ll ans = 1e9;
	for (int i = 0; i <= k; i++) ans = std::min(ans, dis[n + n * i]);
	if (ans == 1e9) {
		for (int i = 1; i <= n; i++) G[i].clear(), G[i + n].clear();
		for (int i = 1; i <= m; i++) {
			int u = x[i], v = y[i];
			G[u].pb({v, 1}), G[v + n].pb({u + n, 1});
		}
		for (int i = 1; i <= n; i++)
			G[i].pb({i + n, n}), G[i + n].pb({i, n});
		dijk(1, n * 2);
		ans = std::min(dis[n], dis[n * 2]);
		int k = ans / n;
		// printf("%d\n", k);
		ans = ans % n + qpow(2, k) - 1;
	}
	printf("%lld\n", ans % P);
	return 0;
}