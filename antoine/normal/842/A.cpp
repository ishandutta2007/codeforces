#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int l, r, x, y, k;
	std::cin >> l >> r >> x >> y >> k;
	for (long long i = x; i <= y; ++i)
		if (i*k >= l && i*k <= r) {
			std::cout << "YES";
			return 0;
		}
	std::cout << "NO";
	return 0;
}