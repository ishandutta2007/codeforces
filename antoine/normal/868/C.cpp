#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <array>

bool f(int i, int j) {
	while (i && j) {
		if ((j & 1) && (i & 1))
			return false;
		i >>= 1;
		j >>= 1;
	}
	return true;
}

int contains[1 << 4] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		int idx = 0;
		for (int j = 0; j < k; ++j) {
			int c;
			std::cin >> c;
			idx |= (c << j);
		}
		contains[idx] = 1;
	}
	if (contains[0]) {
		std::cout << "YES";
		return 0;
	}
	for(int i = 0; i < (1 << 4); ++i)
		for (int j = 0; j < (1 << 4); ++j)
			if (contains[i] && contains[j] && f(i, j)) {
				std::cout << "YES";
				return 0;
			}
	std::cout << "NO";
	return 0;
}