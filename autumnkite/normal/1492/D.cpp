#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int a, b, k;
	std::cin >> a >> b >> k;
	if (k == 0) {
		std::cout << "Yes\n";
		std::string s;
		for (int i = 0; i < b; ++i) {
			s += '1';
		}
		for (int i = 0; i < a; ++i) {
			s += '0';
		}
		std::cout << s << "\n" << s << "\n";
		return 0;
	}
	if (a == 0 || b == 1 || k > a + b - 2) {
		std::cout << "No\n";
		return 0;
	}
	std::cout << "Yes\n";
	std::vector<int> x(a + b), y(a + b);
	int now = 0;
	for (int i = 0; i < a + b && now < b - 2; ++i) {
		if (i != 0 && i != k && i != a + b - 1) {
			x[i] = y[i] = 1;
			++now;
		}
	}
	x[a + b - 1] = y[a + b - 1] = 1;
	x[k] = y[0] = 1;
	for (int i = a + b - 1; i >= 0; --i) {
		std::cout << x[i];
	}
	std::cout << "\n";
	for (int i = a + b - 1; i >= 0; --i) {
		std::cout << y[i];
	}
	std::cout << "\n";
}