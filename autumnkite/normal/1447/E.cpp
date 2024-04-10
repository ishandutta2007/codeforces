#include <bits/stdc++.h>

const int N = 200005, LG = 30;

int n, a[N];

struct Trie {
	static const int N = ::N * LG + 1;

	int cnt, rt, f[N], son[N][2], sz[N];

	Trie() {
		cnt = rt = 1;
	}

	void insert(int v) {
		int u = rt;
		++sz[u];
		for (int i = LG - 1; ~i; --i) {
			if (!son[u][v >> i & 1]) {
				son[u][v >> i & 1] = ++cnt;
			}
			u = son[u][v >> i & 1];
			++sz[u];
		}
	}

	void dfs(int u) {
		if (!u) {
			f[0] = 0;
			return;
		}
		dfs(son[u][0]);
		dfs(son[u][1]);
		if (!son[u][0]) {
			f[u] = f[son[u][1]];
		} else if (!son[u][1]) {
			f[u] = f[son[u][0]];
		} else {
			f[u] = std::min(f[son[u][0]] + sz[son[u][1]] - 1, f[son[u][1]] + sz[son[u][0]] - 1);
		}
	}
} T;

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		T.insert(a[i]);
	}
	T.dfs(T.rt);
	std::cout << T.f[T.rt] << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
}