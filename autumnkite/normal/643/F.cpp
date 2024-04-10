#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, p, q;
	std::cin >> n >> p >> q;
	p = std::min(p, n - 1);
	std::vector<unsigned> C(p + 1);
	for (int i = 0; i <= p; ++i) {
		std::vector<unsigned> a, b;
		for (int j = 0; j < i; ++j) {
			a.push_back(n - j);
			b.push_back(j + 1);
		}
		C[i] = 1;
		for (unsigned &x : a) {
			for (unsigned &y : b) {
				unsigned g = std::__gcd(x, y);
				x /= g, y /= g;
			}
			C[i] *= x;
		}
	}
	unsigned ans = 0;
	for (int i = 1; i <= q; ++i) {
		unsigned pw = 1, sum = 0;
		for (int j = 0; j <= p; ++j) {
			sum += pw * C[j];
			pw *= (unsigned)i;
		}
		ans ^= sum * (unsigned)i;
	}
	std::cout << ans << "\n";
}