#include <bits/stdc++.h>

int n, a[1005];

int main() {
	std::cin >> n;
	for (int i = 2; i <= n; ++i) {
		std::cout << "? " << 1 << " " << i << std::endl;
		std::cin >> a[i];
	}
	std::cout << "? " << 2 << " " << n << std::endl;
	std::cin >> a[1];
	a[1] = a[n] - a[1];
	for (int i = n; i > 1; --i) {
		a[i] -= a[i - 1];
	}
	std::cout << "! ";
	for (int i = 1; i <= n; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}