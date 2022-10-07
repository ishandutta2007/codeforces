#include <bits/stdc++.h>

int n, h, l, r, q;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> h >> l >> r >> q;
	while (q--) {
		int x, hx, y, hy;
		std::cin >> x >> hx >> y >> hy;
		if (x != y) {
			if ((l <= hx && hx <= r) || (l <= hy && hy <= r)) {
				std::cout << abs(hy - hx) + abs(x - y) << "\n";
			} else {
				std::cout << std::min(abs(hx - l) + abs(hy - l), abs(hx - r) + abs(hy - r)) + abs(x - y) << "\n";
			}
		} else {
			std::cout << abs(hx - hy) << "\n";
		}
	}
}