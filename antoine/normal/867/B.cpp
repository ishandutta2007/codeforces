#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <array>
#include <queue>
#include <functional>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int A;
	std::cin >> A;
	if (A == 1) {
		std::cout << "1 1\n1";
		return 0;
	}
	int n = 1;
	while (1 + n / 2 != A)
		++n;
	std::cout << n << " 2\n1 2";
	return 0;
}