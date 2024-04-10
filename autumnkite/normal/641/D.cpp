#include <bits/stdc++.h>

const double pi = acos(-1);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	int n;
	std::cin >> n;
	std::vector<double> a(n + 1), b(n + 1);
	for (int i = 0; i < n; ++i) {
		double v;
		std::cin >> v;
		a[i + 1] = a[i] + v;
	}
	for (int i = 0; i < n; ++i) {
		double v;
		std::cin >> v;
		b[i + 1] = b[i] + v;
	}
	std::vector<double> x(n + 1), y(n + 1);
	for (int i = 0; i <= n; ++i) {
		x[i] = (a[i] + b[i] + sqrt((a[i] + b[i]) * (a[i] + b[i]) - 4 * a[i] + 1e-12)) / 2;
		y[i] = a[i] + b[i] - x[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cout << x[i + 1] - x[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < n; ++i) {
		std::cout << y[i + 1] - y[i] << " ";
	}
	std::cout << "\n";
}