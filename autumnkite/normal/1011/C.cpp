#include <bits/stdc++.h>

const int N = 1005;
const double eps = 1e-9;

int n, m, a[N], b[N];

bool check(double x) {
	for (int i = 0; i < n; ++i) {
		x -= (x + m) / a[i];
		if (x <= -eps) {
			return false;
		}
		x -= (x + m) / b[(i + 1) % n];
		if (x <= -eps) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	double l = 0, r = 1e9;
	for (int i = 0; i < 100; ++i) {
		double mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	if (check(r)) {
		std::cout << r << "\n";
	} else {
		std::cout << -1 << "\n";
	}
}