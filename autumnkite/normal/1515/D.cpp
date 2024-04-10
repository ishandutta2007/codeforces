#include <bits/stdc++.h>

void solve() {
	int n, l, r;
	std::cin >> n >> l >> r;
	std::vector<int> cl(n), cr(n);
	for (int i = 0; i < l; ++i) {
		int v;
		std::cin >> v;
		--v;
		++cl[v];
	}
	for (int i = 0; i < r; ++i) {
		int v;
		std::cin >> v;
		--v;
		++cr[v];
	}
	if (l < r) {
		std::swap(l, r);
		cl.swap(cr);
	}

	std::priority_queue<std::pair<int, int>> Q;
	for (int i = 0; i < n; ++i) {
		Q.emplace(cl[i] - cr[i], i);
	}
	int ans = 0;
	while (l > r) {
		int i = Q.top().second;
		Q.pop();
		--cl[i], --l;
		++cr[i], ++r;
		Q.emplace(cl[i] - cr[i], i);
		ans += 2;
	}
	for (int i = 0; i < n; ++i) {
		ans += abs(cl[i] - cr[i]);
	}
	std::cout << ans / 2 << "\n";
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