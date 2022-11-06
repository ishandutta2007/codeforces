#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::vector<int> a(6);
	for (int i = 0; i < 6; ++i)
		std::cin >> a[i];
	std::sort(a.begin(), a.end());
	do {
		if (a[0] + a[1] + a[2] == a[3] + a[4] + a[5]) {
			std::cout << "YES";
			return 0;
		}
	}
	while (std::next_permutation(a.begin(), a.end()));
	std::cout << "NO";
	return 0;
}