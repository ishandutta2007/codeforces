#include <iostream>
#include <algorithm>
#include <cstring>

long long n, m;
long long K;

bool f(long long x) {
	long long k = K;
	for (long long i = 1; i <= n; ++i) {
		k -= std::min(m, x / i);
		if (k <= 0)
			return true;
	}
	return false;
}

int main() {
	std::cin >> n >> m >> K;
	long long lo = 1;
	long long hi = n*m;
	while (lo < hi) {
		long long mid = (lo + hi) / 2;
		if (f(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	std::cout << lo;
	return 0;
}