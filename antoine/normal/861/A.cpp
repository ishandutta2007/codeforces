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


int countDiv(long long n, long long d) {
	int count = 0;
	while (n % d == 0) {
		n /= d;
		++count;
	}
	return count;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long n, k;
	std::cin >> n >> k;
	int c2 = countDiv(n, 2);
	int c5 = countDiv(n, 5);
	while (c2 < k) {
		++c2;
		n *= 2;
	}
	while (c5 < k) {
		++c5;
		n *= 5;
	}
	std::cout << n;
	return 0;
}