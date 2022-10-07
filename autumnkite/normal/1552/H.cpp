#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	auto query = [&](int d) {
		std::cout << "? " << 200 / d * 200 << "\n";
		for (int x = d; x <= 200; x += d) {
			for (int y = 1; y <= 200; ++y) {
				std::cout << x << " " << y << " ";
			}
		}
		std::cout << std::endl;
		int res;
		std::cin >> res;
		return res;
	};

	int S = query(1);
	int l = 0, r = 8, s = 0;
	while (l + 1 < r) {
		int mid = (l + r + 1) >> 1;
		int t = query(1 << mid);
		if ((t << mid) == S) {
			l = mid;
		} else {
			r = mid;
			s = t;
		}
	}
	int a = abs((S >> (r - 1)) - (s << 1)), b = S / a;
	std::cout << "! " << 2 * (a + b - 2) << std::endl;
}