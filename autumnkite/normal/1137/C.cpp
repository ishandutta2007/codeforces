#include <bits/stdc++.h>

const int N = 100000, M = 100000, D = 50;

int n, m, d;

int Edge, To[M * D], Pr[M * D], Hd[N * D];

void add_Edge(int u, int v) {
	To[Edge] = v, Pr[Edge] = Hd[u], Hd[u] = Edge++;
}

long long S[N];

int idx, dfn[N * D], low[N * D];
int top, sta[N * D];
bool vis[N * D];
int cnt, col[N * D];

void tarjan(int u) {
	dfn[u] = low[u] = idx++;
	sta[top++] = u, vis[u] = true;
	for (int i = Hd[u]; i != -1; i = Pr[i]) {
		int v = To[i];
		if (dfn[v] == -1) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (vis[v]) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		while (vis[u]) {
			int v = sta[--top];
			vis[v] = false;
			col[v] = cnt;
		}
		++cnt;
	}
}

int edge, to[M * D], pr[M * D], hd[N * D];

void add_edge(int u, int v) {
	to[edge] = v, pr[edge] = hd[u], hd[u] = edge++;
}

int deg[N * D];
int w[N * D];
int vis_time[N * D];
int f[N * D];

int dfs(int u) {
	if (f[u] != -1) {
		return f[u];
	}
	f[u] = w[u];
	for (int i = hd[u]; i != -1; i = pr[i]) {
		f[u] = std::max(f[u], dfs(to[i]) + w[u]);
	}
	return f[u];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m >> d;
	for (int i = 0; i < n * d; ++i) {
		Hd[i] = -1;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		for (int j = 0; j < d; ++j) {
			add_Edge(u * d + j, v * d + (j + 1) % d);
		}
	}
	for (int i = 0; i < n; ++i) {
		std::string tmp;
		std::cin >> tmp;
		for (int j = 0; j < d; ++j) {
			S[i] |= 1ll * (tmp[j] - '0') << j;
		}
	}

	for (int i = 0; i < n * d; ++i) {
		dfn[i] = -1;
	}
	for (int i = 0; i < n * d; ++i) {
		if (dfn[i] == -1) {
			tarjan(i);
		}
	}

	for (int i = 0; i < cnt; ++i) {
		hd[i] = -1;
	}
	for (int u = 0; u < n * d; ++u) {
		for (int i = Hd[u]; i != -1; i = Pr[i]) {
			int v = To[i];
			if (col[u] != col[v]) {
				add_edge(col[u], col[v]);
				++deg[col[v]];
			}
		}
	}

	for (int i = 0; i < cnt; ++i) {
		vis_time[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < d; ++j) {
			int u = col[i * d + j];
			if (vis_time[u] != i && S[i] >> j & 1) {
				++w[u];
				vis_time[u] = i;
			}
		}
	}

	for (int i = 0; i < cnt; ++i) {
		f[i] = -1;
	}
	std::cout << dfs(col[0]) << "\n";
}