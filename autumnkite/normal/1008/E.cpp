#include <bits/stdc++.h>

long long n;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n;
	long long x = 0, y = 0, dx = 1, dy = 1;
	while (1) {
		std::cout << x + dx << " " << y + dy << std::endl;
		int res;
		std::cin >> res;
		if (res == 0) {
			return 0;
		} else if (res == 1) {
			x += dx;
			dx = std::min(dx << 1, n - x);
		} else if (res == 2) {
			y += dy;
			dy = std::min(dy << 1, n - y);
		} else {
			dx = std::max(dx >> 1, 1ll);
			dy = std::max(dy >> 1, 1ll);
		}
	}
}