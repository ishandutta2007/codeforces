#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cout << "1";
	}
	std::cout << "\n";
	for (int i = 0; i < n; ++i) {
		if (i < n - 1) {
			std::cout << "8";
		} else {
			std::cout << "9";
		}
	}
	std::cout << "\n";
}