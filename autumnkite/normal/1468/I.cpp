#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	int dx1, dy1, dx2, dy2;
	std::cin >> n;
	std::cin >> dx1 >> dy1;
	std::cin >> dx2 >> dy2;

	int gx = abs(std::__gcd(dx1, dx2));
	int gy = abs(std::__gcd(dy1, dy2));
	long long w = 1ll * dx1 * dy2 - 1ll * dx2 * dy1;
	if (w == 0) {
		std::cout << "NO\n";
		return 0;
	}
	if (gx != 0 && n % gx == 0 && (n / gx) % (w / gx) == 0) {
		std::cout << "YES\n";
		for (int i = 0; i < gx; ++i) {
			for (int j = 0; j < n / gx; ++j) {
				std::cout << i << " " << j << "\n";
			}
		}
		return 0;
	}
	if (gy != 0 && n % gy == 0 && (n / gy) % (w / gy) == 0) {
		std::cout << "YES\n";
		for (int i = 0; i < n / gy; ++i) {
			for (int j = 0; j < gy; ++j) {
				std::cout << i << " " << j << "\n";
			}
		}
		return 0;
	}
	std::cout << "NO\n";
}