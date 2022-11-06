#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>

long long R, d, n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> R >> d >> n;
	int ans = 0;
	for (; n > 0; --n) {
		long long x, y, r;
		std::cin >> x >> y >> r;
		if (x*x + y*y >= (R - d + r) * (R - d + r) && x*x + y*y <= (R - r) * (R - r) && R - d + r >= 0 && R >= r)
			++ans;
	}
	std::cout << ans;
	return 0;
}