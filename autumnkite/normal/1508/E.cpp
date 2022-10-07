#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n), p(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
		p[a[i]] = i;
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v), E[v].push_back(u);
	}

	std::vector<int> fa(n);
	std::vector<int> dep(n);
	std::vector<bool> flag(n);

	std::function<void(int)> dfs = [&](int u) {
		if (fa[u] != -1) {
			E[u].erase(std::find(E[u].begin(), E[u].end(), fa[u]));
		}
		flag[u] = true;
		for (int v : E[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
			flag[u] = flag[u] & (a[v] < a[u]);
		}
	};

	fa[0] = -1;
	dfs(0);

	int x = 0;
	while (x < n - 1 && flag[p[x]]) {
		++x;
	}

	long long sum = 0;
	std::vector<long long> d(n);
	for (int i = x; i >= 0; --i) {
		if (fa[p[i]] != -1) {
			d[p[i]] += dep[p[i]];
			d[fa[p[i]]] -= dep[p[i]];
			--d[fa[p[i]]];
			sum += dep[p[i]];
		}
	}
	
	std::function<void(int)> get_d = [&](int u) {
		for (int v : E[u]) {
			get_d(v);
			d[u] += d[v];
		}
	};

	get_d(0);
	for (int i = 0; i < n; ++i) {
		a[i] += d[i];
	}
	for (int i = 0; i < n; ++i) {
		std::sort(E[i].begin(), E[i].end(), [&](int x, int y) {
			return a[x] < a[y];
		});
	}

	int idx = 0;
	std::function<bool(int)> get_dfn = [&](int u) {
		if (a[u] != idx) {
			return false;
		}
		++idx;
		for (int v : E[u]) {
			if (!get_dfn(v)) {
				return false;
			}
		}
		return true;
	};
	
	if (!get_dfn(0)) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		std::cout << sum << "\n";
		for (int i = 0; i < n; ++i) {
			std::cout << a[i] + 1 << " ";
		}
		std::cout << "\n";
	}
}