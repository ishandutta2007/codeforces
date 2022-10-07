#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(m + 1);
	for (int i = 1; i <= m; ++i) {
		std::cin >> a[i];
		--a[i];
	}

	if (n == 1) {
		std::cout << 0 << "\n";
		return 0;
	}

	std::vector<int> l(n + 2 * m + 2), r(n + 2 * m + 2);
	for (int i = m; i >= 1; --i) {
		r[a[i] - i + m + 1] = r[a[i] - i + m] + 1;
		l[a[i] + i + m + 1] = l[a[i] + i + m + 2] + 1;
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += std::min(n, i + m + 2 - r[i + m + 1]) - std::max(0, i - m - 1 + l[i + m + 1]);
	}
	std::cout << ans << "\n";
}