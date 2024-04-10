#include <bits/stdc++.h>

int n, m;
int p[30];
int now;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		std::cout << m << std::endl;
		int res;
		std::cin >> res;
		if (res == 0) {
			return 0;
		}
		if (res == -1) {
			p[i] = 1;
		} else {
			p[i] = -1;
		}
	}

	int l = 1, r = m;
	while (l <= r) {
		int mid = (l + r) >> 1;
		std::cout << mid << std::endl;
		int res;
		std::cin >> res;
		if (res == 0) {
			return 0;
		}
		res *= p[now], now = (now + 1) % n;
		if (res == -1) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
}