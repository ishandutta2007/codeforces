#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <unordered_set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	int count = 0;
	for (; n > 0; --n) {
		static bool occ[10];
		for (int i = 0; i <= k; ++i)
			occ[i] = false;

		static int a;
		std::cin >> a;
		if (a < 0)
			a *= -1;
		if (a == 0)
			occ[0] = 1;
		else
			for (; a != 0; a /= 10)
				occ[a % 10] = true;

		bool kGood = true;
		for (int i = 0; i <= k; ++i)
			if (!occ[i]) {
				kGood = false;
				break;
			}
		if (kGood)
			++count;
	}
	std::cout << count;
	return 0;
}