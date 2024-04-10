#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	if (n > 1) {
		std::cout << n << " " << n + 1 << " " << n * (n + 1) << "\n";
	} else {
		std::cout << -1 << "\n";
	}
}