#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> G[14];
bool g[14][14][1 << 14];
int gfrv[14][14][1 << 14], f[1 << 14], ffrs[1 << 14], ffrt[1 << 14], ffrm[1 << 14];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int u = 0; u < n; u++)
		for (int v : G[u])
			g[u][v][0] = true, gfrv[u][v][0] = u;
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int s = 0; s < n; s++) {
			for (int t = 0; t < n; t++) {
				if ((mask >> s & 1) || (mask >> t & 1) || s == t || !g[s][t][mask]) continue;
				for (int u : G[t]) {
					if ((mask >> u & 1) || u == gfrv[s][t][mask]) continue;
					int nmask = mask ^ (1 << t);
					if (g[s][u][nmask]) continue;
					g[s][u][nmask] = true;
					gfrv[s][u][nmask] = t;
				}
			}
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for (int mask = 2; mask < (1 << n); mask++) {
		for (int sl = mask; sl; sl = (sl - 1) & mask) {
			int sn = mask ^ sl;
			if (f[mask] <= f[sn] + __builtin_popcount(sl) + 1) continue;
			int found = 0;
			for (int s = 0; s < n; s++) if (sn >> s & 1) {
				for (int t = 0; t < n; t++) if (sn >> t & 1) {
					if (!g[s][t][sl]) continue;
					found = 1;
					f[mask] = f[sn] + __builtin_popcount(sl) + 1;
					ffrs[mask] = s;
					ffrt[mask] = t;
					ffrm[mask] = sl;
					break;
				}
				if (found) break;
			}
		}
	}
	printf("%d\n", f[(1 << n) - 1]);
	int cur = (1 << n) - 1;
	while (cur > 1) {
		int sl = ffrm[cur];
		int s = ffrs[cur], t = ffrt[cur];
		cur ^= sl;
		while (sl) {
			int v = gfrv[s][t][sl];
			printf("%d %d\n", v + 1, t + 1);
			sl ^= (1 << v);
			t = v;
		}
		printf("%d %d\n", s + 1, t + 1);
	}
	return 0;
}