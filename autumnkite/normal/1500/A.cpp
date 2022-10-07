#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		m = std::max(m, a[i]);
	}
	std::vector<std::pair<int, int>> p(2 * m + 1, std::make_pair(-1, -1));
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int v = a[i] + a[j];
			if (p[v].first == -1) {
				p[v] = std::make_pair(i, j);
				continue;
			}
			if (p[v].first != i && p[v].second != j && p[v].second != i) {
				std::cout << "YES\n";
				std::cout << p[v].first + 1 << " " << p[v].second + 1 << " " << i + 1 << " " << j + 1 << "\n";
				return 0;
			}
		}
	}
	std::cout << "NO\n";
}