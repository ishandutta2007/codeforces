#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

int n, rt, d, dep[1005], idx, dfn[1005], ed[1005];
std::vector<int> E[1005];

std::pair<int, int> Query(const std::vector<int> &A) {
	if (A.empty()) {
		return {0, 0x3f3f3f3f};
	}
	printf("? %d", (int)A.size());
	for (int i : A) {
		printf(" %d", i);
	}
	putchar('\n');
	fflush(stdout);
	int x, y;
	scanf("%d%d", &x, &y);
	return {x, y};
}

void dfs(int u, int fa = 0) {
	dfn[u] = ++idx;
	for (int v : E[u]) {
		if (v != fa) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
	ed[u] = idx;
}

bool isGF(int u, int v) {
	return dfn[u] <= dfn[v] && dfn[v] <= ed[u];
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		E[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v), E[v].push_back(u);
	}
	std::vector<int> id;
	for (int i = 1; i <= n; ++i) {
		id.push_back(i);
	}
	std::pair<int, int> tmp = Query(id);
	rt = tmp.first, d = tmp.second;
	idx = 0, dep[rt] = 0, dfs(rt);
	int l = d / 2, r = d, md, x = rt;
	while (l <= r) {
		md = (l + r) >> 1;
		id.clear();
		for (int i = 1; i <= n; ++i) {
			if (isGF(x, i) && dep[i] == md) {
				id.push_back(i);
			}
		}
		tmp = Query(id);
		if (tmp.second == d) {
			x = tmp.first;
			l = md + 1;
		} else {
			r = md - 1;
		}
	}
	idx = 0, dep[x] = 0, dfs(x);
	id.clear();
	for (int i = 1; i <= n; ++i) {
		if (dep[i] == d) {
			id.push_back(i);
		}
	}
	printf("! %d %d\n", x, Query(id).first);
	fflush(stdout);
	static char ret[25];
	scanf("%s", ret);
}

int main() {
	int T = 1;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}
/*
1
10
9 7
6 10
8 2
4 10
1 5
6 8
3 10
3 9
2 5

6 5
*/