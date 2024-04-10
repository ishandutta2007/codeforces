#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int mx = *std::max_element(a.begin(), a.end());
	if (mx == 0) {
		std::cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			std::cout << 1 << " ";
		}
		std::cout << "\n";
		return 0;
	}
	int p = 0;
	while (p < n && (a[p] != mx || a[(p + n - 1) % n] == mx)) {
		++p;
	}
	if (p == n) {
		std::cout << "NO\n";
		return 0;
	}

	std::vector<long long> b(n);
	b[p] = mx;
	for (int i = (p + n - 1) % n; i != p; i = (i + n - 1) % n) {
		b[i] = b[(i + 1) % n] + a[i];
		if (b[i] == mx) {
			b[i] += b[(i + 1) % n];
		}
	}
	std::cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		std::cout << b[i] << " ";
	}
	std::cout << "\n";
}