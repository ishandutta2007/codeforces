#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
namespace MF {
const int V = 105;
const int E = 10000;
int n, head[V], to[E], cap[E], nxt[E], eid;
inline void Init(int _n) {
	n = _n;
	memset(head, -1, n << 2);
	eid = 0;
}
inline void _add_edge(int u, int v, int w) {
	to[eid] = v;
	cap[eid] = w;
	nxt[eid] = head[u];
	head[u] = eid++;
}
inline void add_edge(int u, int v, int w) {
	_add_edge(u, v, w);
	_add_edge(v, u, 0);
}
int lvl[V], que[V];
inline bool bfs(int s, int t) {
	memset(lvl, -1, n << 2);
	int ql = 0, qr = -1;
	lvl[s] = 0;
	que[++qr] = s;
	while (ql <= qr) {
		int u = que[ql++];
		for (int i = head[u]; ~i; i = nxt[i]) if (cap[i] > 0) {
			int v = to[i];
			if (lvl[v] == -1) {
				lvl[v] = lvl[u] + 1;
				que[++qr] = v;
			}
		}
	}
	return lvl[t] != -1;
}
int iter[V];
int dfs(int u, int t, int fl) {
	if (u == t) return fl;
	int res = 0;
	for (int &i = iter[u]; ~i; i = nxt[i]) if (cap[i] > 0) {
		int v = to[i];
		if (lvl[v] == lvl[u] + 1) {
			int tmp = dfs(v, t, min(fl, cap[i]));
			res += tmp;
			fl -= tmp;
			cap[i] -= tmp;
			cap[i ^ 1] += tmp;
			if (!fl) break;
		}
	}
	if (!res) lvl[u] = -1;
	return res;
}
inline int solve(int s, int t) {
	int res = 0;
	while (bfs(s, t)) {
		memcpy(iter, head, n << 2);
		res += dfs(s, t, INF);
	}
	return res;
}
}
int n, m, K, eu[1300], ev[1300], fr[55][55], need[55], del[105];
long long dp[55][55];
inline int calc() {
	int s = 0, t = 2 * n + 1;
	MF::Init(2 * n + 2);
	for (int i = 1; i <= n; i++) MF::add_edge(s, i, !del[i]), MF::add_edge(i + n, t, !del[i + n]);
	for (int i = 1; i <= m; i++) MF::add_edge(eu[i], ev[i] + n, INF);
	return MF::solve(s, t);
}
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eu[i] = u;
		ev[i] = v;
	}
	int mv = calc();
	memset(dp, -1, sizeof(dp));
	dp[0][mv] = 0;
	for (int i = 1; i <= K; i++) {
		long long x, y;
		scanf("%lld%lld", &x, &y);
		for (int j = 0; j < n; j++) if (dp[i - 1][j] != -1) {
			for (int k = 0; k <= j; k++) if (k < n - i) {
				long long cur = dp[i - 1][j] + max(0ll, x - y * (j - k));
				if (dp[i][k] < cur) dp[i][k] = cur, fr[i][k] = j;
			}
		}
	}
	int best = 0;
	for (int i = 0; i < n - K; i++) if (dp[K][i] > dp[K][best]) best = i;
	for (int i = K; i >= 1; i--) {
		need[i] = fr[i][best] - best;
		best = fr[i][best];
	}
	vector<int> ans;
	for (int i = 1; i <= K; i++) {
		for (int tmp = 0; tmp < need[i]; tmp++) {
			for (int u = 1; u <= n * 2; u++) if (!del[u]) {
				del[u] = 1;
				if (calc() == mv - 1) { ans.push_back((u <= n ? u : -(u - n))); mv--; break; }
				del[u] = 0;
			}
		}
		ans.push_back(0);
	}
	printf("%d\n", (int)ans.size());
	for (int x : ans) printf("%d ", x);
	return 0;
}