#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> x, y;
	for (int i = 0; i < 2 * n; ++i) {
		int vx, vy;
		std::cin >> vx >> vy;
		if (vx) {
			x.push_back(abs(vx));
		} else {
			y.push_back(abs(vy));
		}
	}
	std::sort(x.begin(), x.end());
	std::sort(y.begin(), y.end());
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}