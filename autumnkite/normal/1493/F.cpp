#include <bits/stdc++.h>

bool query(int h, int w, int i1, int j1, int i2, int j2) {
	std::cout << "? " << h << " " << w << " " << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << std::endl;
	int res;
	std::cin >> res;
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	
	int n, m;
	std::cin >> n >> m;
	auto row = [&](int t) {
		if (n % t != 0 || (t > 2 && !(t & 1))) {
			return false;
		} else if (t == 2) {
			return query(n / 2, m, 0, 0, n / 2, 0);
		} else {
			return query(n / t * (t - 1) / 2, m, 0, 0, n / t * (t - 1) / 2, 0) &&
			       query(n / t * (t - 1) / 2, m, 0, 0, n / t * (t + 1) / 2, 0);
		}
	};
	auto col = [&](int t) {
		if (m % t != 0 || (t > 2 && !(t & 1))) {
			return false;
		} else if (t == 2) {
			return query(n, m / 2, 0, 0, 0, m / 2);
		} else {
			return query(n, m / t * (t - 1) / 2, 0, 0, 0, m / t * (t - 1) / 2) &&
			       query(n, m / t * (t - 1) / 2, 0, 0, 0, m / t * (t + 1) / 2);
		}
	};
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		int c = 1;
		while (row(i)) {
			n /= i;
			++c;
		}
		ans *= c;
	}
	for (int i = 2; i <= m; ++i) {
		int c = 1;
		while (col(i)) {
			m /= i;
			++c;
		}
		ans *= c;
	}
	std::cout << "! " << ans << std::endl;
}