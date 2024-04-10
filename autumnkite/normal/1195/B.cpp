#include <bits/stdc++.h>

int n, k;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k;
	for (int i = 0; i <= n; ++i) {
		if (1ll * i * (i + 1) / 2 - (n - i) == k) {
			std::cout << n - i << "\n";
			return 0;
		}
	}
}