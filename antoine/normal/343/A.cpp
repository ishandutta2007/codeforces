#include <iostream>
#include <algorithm>
#include <cstring>

long long f(long long a, long long b) {
	if (b == 0) return 0;
	long long c = a / b;
	return c + f(b, a - c * b);
}

int main() {
	long long a, b;
	std::cin >> a >> b;
	std::cout << f(a, b);
	return 0;
}