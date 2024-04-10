#include <bits/stdc++.h>

const int P = 1000000007;

long long x, n;

int qpow(int a, long long b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> x >> n;
	if (x == 0) {
		std::cout << 0 << "\n";
		return 0;
	}
	x *= 2;
	int t = qpow(2, n);
	std::cout << ((x - 1) % P * t + 1) % P << "\n";
}