#include <iostream>
#include <algorithm>
#include <cstring>

int n, k, t;

int f() {
	if (t < k)
		return t;
	if (t > n)
		return k - (t - n);
	return k;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> k >> t;
	std::cout << std::max(0, f());


	return 0;
}