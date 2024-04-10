#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, x;
	std::cin >> n >> x;

	int less = 0;
	int eq = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		if (a < x)
			++less;
		if (a == x)
			++eq;
	}
	std::cout << (x - less + eq) << '\n';
	return 0;
}