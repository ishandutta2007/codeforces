#include <bits/stdc++.h>

const int N = 200000, LG = 18, P = 1000000007;

int n;
int a[N];
int id[N + 1];

int inv[N + 1], phi[N + 1], mu[N + 1], f[N + 1];
std::vector<int> E[N];

void init() {
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	}
	for (int i = 1; i <= n; ++i) {
		phi[i] += i;
		for (int j = i + i; j <= n; j += i) {
			phi[j] -= phi[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		mu[i] += i == 1;
		for (int j = i + i; j <= n; j += i) {
			mu[j] -= mu[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			f[j] = (f[j] + 1ll * i * inv[phi[i]] * mu[j / i]) % P;
		}
	}
}

int idx, dfn[N], dep[N];
int st[LG + 1][N * 2 - 1];

void dfs(int u, int fa) {
	dfn[u] = idx;
	st[0][idx++] = u;
	for (int i = 0; i < (int)E[u].size(); ++i) {
		int v = E[u][i];
		if (v != fa) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
			st[0][idx++] = u;
		}
	}
}

int Log[N * 2];

int min(int u, int v) {
	return dep[u] < dep[v] ? u : v;
}

void initST() {
	Log[1] = 0;
	for (int i = 2; i <= idx; ++i) {
		Log[i] = Log[i >> 1] + 1;
	}
	for (int i = 1; i <= LG; ++i) {
		for (int j = 0; j + (1 << i) <= idx; ++j) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int LCA(int u, int v) {
	int l = dfn[u], r = dfn[v];
	if (l > r) {
		std::swap(l, r);
	}
	++r;
	int t = Log[r - l];
	return min(st[t][l], st[t][r - (1 << t)]);
}

int top, sta[N];
std::vector<int> G[N];

void insert(int u) {
	if (!top) {
		sta[top++] = u;
		return;
	}
	int x = sta[top - 1], y, z = LCA(x, u);
	if (z == x) {
		sta[top++] = u;
		return;
	}
	while (top > 1 && dfn[y = sta[top - 2]] > dfn[z]) {
		G[y].push_back(x);
		--top;
		x = sta[top - 1];
	}
	G[z].push_back(x);
	--top;
	if (top == 0 || z != sta[top - 1]) {
		sta[top++] = z;
	}
	sta[top++] = u;
}

int sum[N];

void get_sum(int u, int d) {
	sum[u] = a[u] % d == 0 ? phi[a[u]] : 0;
	for (int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		get_sum(v, d);
		sum[u] = (sum[u] + sum[v]) % P;
	}
}

void get_ans(int rt, int u, int &res) {
	for (int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i];
		get_ans(rt, v, res);
		res = (res + 1ll * (sum[rt] + P - sum[v]) * sum[v] % P * (dep[v] - dep[u])) % P;
	}
	G[u].clear();
}

bool cmp(int x, int y) {
	return dfn[x] < dfn[y];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		id[a[i]] = i;
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	init();
	dfs(0, -1);
	initST();
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		top = 0;
		std::vector<int> nd;
		for (int j = i; j <= n; j += i) {
			nd.push_back(id[j]);
		}
		std::sort(nd.begin(), nd.end(), cmp);
		for (int j = 0; j < (int)nd.size(); ++j) {
			insert(nd[j]);
		}
		while (top > 1) {
			G[sta[top - 2]].push_back(sta[top - 1]);
			--top;
		}
		get_sum(sta[0], i);
		int res = 0;
		get_ans(sta[0], sta[0], res);
		ans = (ans + 1ll * f[i] * res) % P;
	}
	std::cout << 2ll * ans * inv[n] % P * inv[n - 1] % P << "\n";
}