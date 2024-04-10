#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	auto solve = [&](int x) {
		std::vector<int> f(n, 1);
		for (int t = 1; t < k; ++t) {
			std::vector<int> g(n);
			int sum = 0;
			for (int i = 0, j = 0; i < n; ++i) {
				while (j < i && a[i] - a[j] >= x) {
					sum = (sum + f[j]) % P;
					++j;
				}
				g[i] = sum;
			}
			f.swap(g);
		}
		return std::accumulate(f.begin(), f.end(), 0ll) % P;
	};
	int ans = 0;
	for (int i = 1; i <= a[n - 1] / (k - 1); ++i) {
		ans = (ans + solve(i)) % P;
	}
	std::cout << ans << "\n";
}