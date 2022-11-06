#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		if (a & 1) {
			std::cout << "First";
			return 0;
		}
	}
	std::cout << "Second";
	// a. sum of all odd: 1 wins
	// b. sum of all odd:
	return 0;
}