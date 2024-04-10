#include <bits/stdc++.h>

std::mt19937 rnd(std::chrono::system_clock().now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, st, x;
	std::cin >> n >> st >> x;
	int mx = -1, id = -1;
	for (int i = 1, p = st; i <= 500 && p != -1; ++i) {
		std::cout << "? " << p << std::endl;
		int val, nx;
		std::cin >> val >> nx;
		if (val <= x || mx == -1) {
			if (val > mx) {
				mx = val;
				id = nx;
			}
		}
		p = nx;
	}
	for (int i = 1; i <= 500; ++i) {
		int p = rnd() % n + 1;
		std::cout << "? " << p << std::endl;
		int val, nx;
		std::cin >> val >> nx;
		if (val <= x) {
			if (val > mx) {
				mx = val;
				id = nx;
			}
		}
	}
	while (id != -1 && mx < x) {
		std::cout << "? " << id << std::endl;
		std::cin >> mx >> id;
	}
	if (mx < x) {
		std::cout << "! " << -1 << std::endl;
	} else {
		std::cout << "! " << mx << std::endl;
	}
}