#include <bits/stdc++.h>

class disjoint_set {
	std::vector<int> fa;

public:
	disjoint_set(int n) : fa(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	int idx = 0;
	std::vector<int> l(n), r(n);

	std::function<void(int, int)> dfs = [&](int u, int fa) {
		if (fa != -1 && (int)E[u].size() == 1) {
			l[u] = idx++;
		} else {
			l[u] = idx;
		}
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
			}
		}
		r[u] = idx;
	};

	dfs(0, -1);

	std::vector<int> id(n);
	for (int i = 0; i < n; ++i) {
		id[i] = i;
	}
	std::sort(id.begin(), id.end(), [&](int x, int y) {
		return a[x] < a[y];
	});

	disjoint_set D(idx + 1);
	long long ans = 0;
	std::vector<int> v;
	for (auto i = id.begin(), j = id.begin(); i != id.end(); i = j) {
		j = i;
		while (j != id.end() && a[*j] == a[*i]) {
			if (D.find(l[*j]) != D.find(r[*j])) {
				v.push_back(*j);
			}
			++j;
		}
		for (auto k = i; k != j; ++k) {
			if (D.merge(l[*k], r[*k])) {
				ans += a[*k];
			}
		}
	}
	std::sort(v.begin(), v.end());

	std::cout << ans << " " << v.size() << "\n";
	for (int x : v) {
		std::cout << x + 1 << " ";
	}
	std::cout << "\n";
}