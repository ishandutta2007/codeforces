#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	std::array<std::vector<std::pair<int, int>>, 4> a;
	for (int i = 0; i < n; ++i) {
		int w, p, q;
		std::cin >> w >> p >> q;
		a[p << 1 | q].emplace_back(w, i);
	}
	for (int i = 0; i < 4; ++i) {
		std::sort(a[i].begin(), a[i].end());
	}

	int p = std::min(a[1].size(), a[2].size());
	long long ans = INF;
	long long sum = 0;
	for (int i = 0; i < p; ++i) {
		sum += a[1][i].first;
		sum += a[2][i].first;
	}
	for (int i = 0; i <= (int)a[3].size(); ++i) {
		while (p && i + p > k) {
			--p;
			sum -= a[1][p].first;
			sum -= a[2][p].first;
		}
		if (i + p >= k) {
			ans = std::min(ans, sum);
		}
		if (i < (int)a[3].size()) {
			sum += a[3][i].first;
		}
	}
	if (ans == INF) {
		std::cout << -1 << "\n";
	} else {
		std::cout << ans << "\n";
	}
}