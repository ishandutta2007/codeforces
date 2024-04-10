#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long
#define pii pair<int, int>

const int N = 2e5 + 5;

int n;
ll ans = 0;
ll f[N][2], g[N][2];
vector<pii> G[N];

void dfs(int p, int fw, int fa) {
	f[p][0] = 1, g[p][0] = 1;
	for (auto& par : G[p]) {
		int e = par.first;
		if (e == fa) {
			continue;
		}
		dfs(e, par.second, p);
		ans += f[p][0] * (g[e][0] + g[e][1]);
		ans += f[p][1] * g[e][0];
		ans += g[p][0] * (f[e][0] + f[e][1]);
		ans += g[p][1] * f[e][0];
		f[p][0] += f[e][0];
		f[p][1] += f[e][1];
		g[p][0] += g[e][0];
		g[p][1] += g[e][1];
	}
//	cerr << p << " " << f[p][0] << " " << f[p][1] << " " << g[p][0] << " " << g[p][1] << '\n';
	if (fa) {
		if (fw) {
			f[p][1] += f[p][0];
			f[p][0] = 0;
			g[p][1] = 0;
		} else {
			f[p][1] = 0;
			g[p][1] += g[p][0];
			g[p][0] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v, w; i < n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	dfs(1, -1, 0);
	printf("%I64d\n", ans);
	return 0;
}