#include <iostream>
#include <algorithm>
#include <cstring>


int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	int n;
	std::cin >> n;

	int ansA = 0;
	int ansB = 0;
	for (int a = 0; a < n; ++a) {
		int b = n - a;
		if (b == 0) continue;
		if (gcd(a, b) != 1)
			continue;
		if (a >= b)
			continue;
		ansA = a;
		ansB = b;
	}
	std::cout << ansA << ' ' << ansB;

	return 0;
}