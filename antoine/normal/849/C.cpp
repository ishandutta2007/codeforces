#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int k;
	char letter = 'a';
	std::cout << 'z';
	std::cin >> k;
	int n = 10000;
	while (k > 0) {
		while (n * (n - 1) / 2 > k)
			--n;
		k -= n*(n - 1) / 2;
		for (int i = 0; i < n; ++i)
			std::cout << letter;
		++letter;
	}
	return 0;
}//