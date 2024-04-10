#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	if (n == 0) {
		std::cout << 'a' << "\n";
		return 0;
	}
	char c = 'a';
	for (int i = n + 1; i >= 2; --i) {
		while (n >= 1ll * i * (i - 1) / 2) {
			for (int t = 0; t < i; ++t) {
				std::cout << c;
			}
			++c;
			n -= i * (i - 1) / 2;
		}
	}
	std::cout << "\n";
}