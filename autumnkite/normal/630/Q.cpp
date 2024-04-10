#include <bits/stdc++.h>

const double pi = acos(-1);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	int l3, l4, l5;
	std::cin >> l3 >> l4 >> l5;
	double ans = 0;
	ans += sqrt(2) / 12 * l3 * l3 * l3;
	ans += sqrt(3.0 / 4 * l4 * l4 - 1.0 / 4 * l4 * l4) / 3 * l4 * l4;
	double l = 1.0 * l5 / 2 / sin(pi / 5), m = sqrt(l * l - 1.0 * l5 * l5 / 4);
	ans += l5 * m / 2 * 5 * sqrt(3.0 / 4 * l5 * l5 - m * m) / 3;
	std::cout << ans << "\n";
}