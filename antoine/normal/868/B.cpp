#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

std::string pass;
int n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	double h, m, s, t1, t2;
	std::cin >> h >> m >> s >> t1 >> t2;
	double a[3];
	a[0] = h + m / 60.0 + s / 3600.0;
	a[1] = m / 5.0 + s / (5*60.0);
	a[2] = s / 5.0;

	if (t1 > t2)
		std::swap(t1, t2);
	bool b[3] = { false, false, false };
	for (auto &&x : a) {
		b[0] |= x < t1;
		b[1] |= t1 < x && x < t2;
		b[2] |= t2 < x;
	}
	if (!b[1] || (!b[0] && !b[2]))
		std::cout << "YES";
	else
		std::cout << "NO";

	return 0;
}