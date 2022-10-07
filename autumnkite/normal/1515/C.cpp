#include <bits/stdc++.h>

void solve() {
	int n, m, x;
	std::cin >> n >> m >> x;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::priority_queue<std::pair<int, int>> Q;
	for (int i = 0; i < m; ++i) {
		Q.emplace(0, i);
	}
	std::cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		auto tmp = Q.top();
		Q.pop();
		tmp.first -= a[i];
		std::cout << tmp.second + 1 << " ";
		Q.push(tmp);
	}
	std::cout << "\n";
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