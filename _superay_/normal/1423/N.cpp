#include <bits/stdc++.h>
using namespace std;
const int N = 12505;
const int M = 1000005;
int n, m, w[N], a[N], b[M], eu[M], ev[M];
bool vis[M * 2];
vector<pair<int, int> > G[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].emplace_back(v, i);
		G[v].emplace_back(u, i);
		b[i] = 1;
		eu[i] = u, ev[i] = v;
	}
	for (int i = 1; i <= n; i++) w[i] = (int)G[i].size(), a[i] = 0;
	for (int u = 1; u <= n; u++) {
		int sz = 0;
		for (auto &e : G[u]) {
			int v = e.first, id = e.second;
			if (v > u) continue;
			sz++;
			if (a[v]) {
				a[v]--;
				b[id]++;
				w[u]++;
			}
		}
		int x;
		for (x = w[u] - sz; x <= w[u]; x++) vis[x] = 0;
		for (auto &e : G[u]) {
			int v = e.first;
			if (v > u) continue;
			vis[w[v]] = 1;
		}
		for (x = w[u] - sz; x <= w[u]; x++) if (!vis[x]) break;
		x = w[u] - x;
		for (auto &e : G[u]) {
			if (!x) break;
			int v = e.first, id = e.second;
			if (v > u) continue;
			x--;
			a[v]++;
			b[id]--;
			w[u]--;
		}
	}
	int cc = 0;
	for (int i = 1; i <= n; i++) if (a[i]) cc++;
	printf("%d\n", cc);
	for (int i = 1; i <= n; i++) if (a[i]) printf("%d\n", i);
	for (int i = 1; i <= m; i++) printf("%d %d %d\n", eu[i], ev[i], b[i]);
	return 0;
}