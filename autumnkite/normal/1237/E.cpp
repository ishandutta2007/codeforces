#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	int l = 0, r = 0;
	while (1) {
		if (l + r + 1 > n) {
			std::cout << 0 << "\n";
			return 0;
		}
		if (l + r + 1 == n || l + r + 2 == n) {
			std::cout << 1 << "\n";
			return 0;
		}
		int nl = l + r + 1, nr = l + r + 1;
		if (!(l & 1)) {
			++nr;
		}
		l = nl, r = nr;
	}
}