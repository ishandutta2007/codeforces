#include <bits/stdc++.h>

const double pi = acos(-1);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	int n;
	double r;
	std::cin >> n >> r;
	double a = tan(pi / n), b = tan(pi / (2 * n));
	std::cout << a * b / (a + b) * n * r * r << "\n";
}