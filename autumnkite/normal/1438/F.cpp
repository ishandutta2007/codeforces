#include <bits/stdc++.h>

std::mt19937 rnd(time(0));

int h, n, c[1 << 18];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> h;
	n = (1 << h) - 1;
	for (int i = 1; i <= 420; ++i) {
		int u, v, w;
		do {
			u = rnd() % n + 1;
			v = rnd() % n + 1;
			w = rnd() % n + 1;
		} while (u == v || v == w || u == w);
		std::cout << "? " << u << " " << v << " " << w << std::endl;
		int x;
		std::cin >> x;
		++c[x];
	}
	int v1 = 0, v2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (!v1 || c[i] > c[v1]) {
			v2 = v1, v1 = i;
		} else if (!v2 || c[i] > c[v2]) {
			v2 = i;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (i != v1 && i != v2) {
			std::cout << "? " << v1 << " " << v2 << " " << i << std::endl;
			int x;
			std::cin >> x;
			if (x == i) {
				std::cout << "! " << x << std::endl;
				return 0;
			}
		}
	}
}