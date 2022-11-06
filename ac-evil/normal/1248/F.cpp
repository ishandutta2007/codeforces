#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define pii pair<int, int>

inline int read() {
    int w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

const int maxn = 1000000 + 5;

int T, N, M;

struct Edge {
	int u, v, pre;
} e[maxn << 1];
int m, G[maxn];
void clear(int n) {
	rep(i, 1, n) G[i] = -1;
	m = 0;
}
void add(int u, int v) {
	e[m++] = (Edge){u, v, G[u]};
	G[u] = m-1;
}

int st[maxn], l, r;
int dfn[maxn], low[maxn], dfs_clock = 0, border;
int sccno[maxn], scc_cnt;
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++dfs_clock;
	st[++l] = u;
	for (register int i = G[u]; ~i; i = e[i].pre) {
		int v = e[i].v;
		if (dfn[v] <= border) {
			tarjan(v, u);
			chkmin(low[u], low[v]);
		} else if (!sccno[v]) chkmin(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		for (scc_cnt++;;) {
			int x = st[l--];
			sccno[x] = scc_cnt;
			if (x == u) break;
		}
	}
}

int deg[maxn];

void solve() {
	rep(i, 0, m-1) {
		int u = sccno[e[i].u], v = sccno[e[i].v];
		if (u ^ v) deg[v]++;
	}
	int left = 0, right = 0;
	if (scc_cnt > 1)
		rep(i, 1, scc_cnt)
			if (!deg[i]) {
				printf("Yes\n");
				rep(x, 1, N) if (sccno[x] == scc_cnt) left++; else right++;
				printf("%d %d\n", left, right);
				rep(x, 1, N) if (sccno[x] == scc_cnt) printf("%d ", x);
				printf("\n");
				rep(x, 1, N) if (sccno[x] ^ scc_cnt) printf("%d ", x);
				printf("\n");
				return;
			}
	printf("No\n");
}

int main() {
	T = read();

	while (T--) {
		N = read(), M = read();
		clear(N);
		rep(i, 1, M) {
			int u = read(), v = read();
			if (u == v) continue;
			add(v, u);
		}
		l = 0;
		border = dfs_clock;
		rep(i, 1, N)
			if (dfn[i] <= border)
				tarjan(i, i);
		solve();
		// clear module
		rep(i, 1, N) sccno[i] = 0;
		rep(i, 1, scc_cnt) deg[i] = 0;
		scc_cnt = 0;
	}

    return 0;
}