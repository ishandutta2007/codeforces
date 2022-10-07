#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	int n, x;
	std::cin >> n >> x;
	std::vector<int> a(n), b;
	int sum = 0, sn = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (2 * a[i] > x) {
			b.push_back(a[i]);
			sum += a[i];
		} else {
			sn += a[i];
		}
	}
	int m = b.size();

	std::vector<std::vector<double>> f(m + 1, std::vector<double>(sum + 1));
	f[0][0] = 1;
	int c = 0, s = 0;
	for (int v : b) {
		if (2 * v > x) {
			++c, s += v;
			for (int i = c; i >= 1; --i) {
				for (int j = s; j >= v; --j) {
					f[i][j] += f[i - 1][j - v] * i / (m - i + 1);
				}
			}
		}
	}
	
	double ans = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= sum; ++j) {
			ans += f[i][j] * std::min(1.0 * (n + i) * x / 2, 1.0 * j) / i;
		}
	}
	std::cout << ans + sn << "\n";
}