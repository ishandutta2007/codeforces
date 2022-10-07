#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	for (int i = n / 2; i >= 1; --i) {
		std::cout << n - 2 * i + 1 << " ";
	}
	for (int i = 1; i <= n / 2; ++i) {
		std::cout << n - 2 * i + 1 << " ";
	}
	for (int i = (n - 1) / 2; i >= 1; --i) {
		std::cout << n - 2 * i << " ";
	}
	std::cout << n << " ";
	for (int i = 1; i <= (n - 1) / 2; ++i) {
		std::cout << n - 2 * i << " ";
	}
	std::cout << n << "\n";
}