#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> A(n);
	for (int i = 1; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		A[x].push_back(i);
	}
	std::vector<std::vector<int>> B(n);
	for (int i = 1; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		B[x].push_back(i);
	}
	
	int idx = 0;
	std::vector<int> dfn(n), sz(n);
	std::function<void(int)> init = [&](int u) {
		dfn[u] = idx++;
		sz[u] = 1;
		for (int v : B[u]) {
			init(v);
			sz[u] += sz[v];
		}
	};
	init(0);

	std::set<std::pair<int, int>> S;
	S.emplace(-1, -1);
	S.emplace(n, n);
	auto check = [&](int u, int v) {
		if (u == -1 || u == n || v == -1) {
			return false;
		}
		if (v == n) {
			return true;
		}
		return dfn[u] + sz[u] <= dfn[v];
	};
	int now = 0, ans = 0;
	std::function<void(int)> dfs = [&](int u) {
		auto it = S.emplace(dfn[u], u).first, pr = std::prev(it), nx = std::next(it);
		int tmp = now;
		now -= check(pr->second, nx->second);
		now += check(pr->second, u);
		now += check(u, nx->second);
		ans = std::max(ans, now);
		for (int v : A[u]) {
			dfs(v);
		}
		S.erase(std::make_pair(dfn[u], u));
		now = tmp;
	};
	dfs(0);
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}