#include <iostream>

long long pow(long long n, long long p) {
	long long ans = 1;
	while (p != 0) {
		if ((p & 1) != 0)
			ans *= n;

		n *= n;
		p >>= 1;
	}
	return ans;
}

long long countDigits(long long n) {
	if (n < 0)
		n *= -1;
	if (n <= 9)
		return 1;
	long long count = 0;
	do {
		n /= 10;
		++count;
	} while (n != 0);
	return count;
}

long long h(long long n) {
	if (n <= 9)
		return n;
	long long ans = 9;
	for (; n > 9; --n) {
		long long digit = n % 10;
		long long m = n;
		while (m / 10 != 0)
			m /= 10;
		if (m == digit)
			++ans;
	}
	return ans;
}

long long g(long long n) {
	if (n <= 9999)
		return h(n);

	long long digitCount = countDigits(n);
	long long ans = 9 + pow(10, digitCount - 2) - 1;

	long long leading = n / pow(10, digitCount - 1);
	if (n % 10 < leading) {
		n /= 10;
		n *= 10;
		if (countDigits(--n) != digitCount)
			return ans;
	}
	long long p = pow(10LL, digitCount - 1);
	n %= p;
	n /= 10;
	return ans + (n + 1) + (leading - 1) * pow(10, digitCount - 2);
}

long long f(long long l, long long r) {
	return g(r) - g(l - 1);
}

int main() {
	long long l, r;
	std::cin >> l >> r;
	std::cout << f(l, r);
	return 0;
}