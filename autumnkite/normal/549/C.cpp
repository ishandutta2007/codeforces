#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	k = n - k;
	int c[2] = {0, 0};
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		++c[v & 1];
	}
	if (k == 0) {
		if (c[1] & 1) {
			std::cout << "Stannis\n";
		} else {
			std::cout << "Daenerys\n";
		}
		return 0;
	}
	if (!(k & 1)) {
		if (n & 1 && c[0] <= k / 2) {
			std::cout << "Stannis\n";
		} else {
			std::cout << "Daenerys\n";
		}
	} else {
		if (c[1] <= k / 2 || (c[0] <= k / 2 && n & 1)) {
			std::cout << "Daenerys\n";
		} else {
			std::cout << "Stannis\n";
		}
	}
}