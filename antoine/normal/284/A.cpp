#include <iostream>
#include <algorithm>
#include <cstring>

int f(int x, int p) {
	int n = x;
	for(int pow = 1; pow <= p - 2; ++pow) {
		if (n == 1)
			return false;
		n = (n*x) % p;
	}
	return n == 1;
}

int main() {
	int p;
	std::cin >> p;
	int ans = 0;
	for (int x = 1; x < p; ++x) {
		if (f(x, p))
			++ans;
	}
	std::cout << ans;
	return 0;
}