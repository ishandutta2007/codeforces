#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	int K = 0;
	int R = -1;
	for (int i = 1; i <= n; ++i) {
		if (n - i - (n - 1) / i > R) {
			R = n - i - (n - 1) / i;
			K = i;
		}
	}
	std::vector<bool> vis(n);
	while (std::accumulate(vis.begin(), vis.end(), 0) < R) {
		std::vector<int> p;
		for (int i = 0; i < n; ++i) {
			if (i % K && !vis[i]) {
				p.push_back(i);
			}
		}
		std::cout << K << " ";
		for (int i = 0; i < K; ++i) {
			std::cout << p[i] + 1 << " ";
			vis[p[i]] = true;
		}
		std::cout << std::endl;
		int x;
		std::cin >> x;
		--x;
		for (int i = 0; i < K; ++i) {
			vis[(i + x) % n] = false;
		}
	}
	std::cout << 0 << std::endl;
}