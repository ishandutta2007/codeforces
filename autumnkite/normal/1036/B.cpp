#include <bits/stdc++.h>

long long n, m, k;

long long solve(long long n, long long m, long long k) {
	k -= m;
	return m + k - 2 * (k & 1);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> m >> k;
		if (n > m) {
			std::swap(n, m);
		}
		if (k < m) {
			std::cout << -1 << "\n";
			continue;
		}
		if ((m - n) & 1) {
			std::cout << std::max(solve(n - 1, m, k - 1), solve(n, m - 1, k - 1)) << "\n";
		} else {
			std::cout << solve(n, m, k) << "\n";
		}
	}
}