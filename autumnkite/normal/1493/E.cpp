#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string l, r;
	std::cin >> l >> r;
	if (l == r) {
		std::cout << r << "\n";
	} else if (l[0] == '0') {
		std::cout << std::string(n, '1') << "\n";
	} else if (r[n - 1] == '0') {
		int p = n - 1;
		while (l[p] == '1') {
			l[p] = '0';
			--p;
		}
		l[p] = '1';
		if (l < r) {
			r[n - 1] = '1';
			std::cout << r << "\n";
		} else {
			std::cout << r << "\n";
		}
	} else {
		std::cout << r << "\n";
	}
}