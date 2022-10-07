#include <bits/stdc++.h>

std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());

int ran(int l, int r) {
	return rnd() % (r - l) + l;
}

const int LIM = 1000000;

int qpow(int a, int b, int p) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % p;
		}
		a = 1ll * a * a % p;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::string a, b;
	std::cin >> a >> b;

	std::vector<bool> is_prime(LIM + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= LIM; ++i) {
		if (is_prime[i]) {
			for (int j = i + i; j <= LIM; j += i) {
				is_prime[j] = false;
			}
		}
	}

	int d = 3;
	while (1) {
		if (is_prime[d]) {
			std::vector<int> sum(d);
			for (int i = 0; i < n; ++i) {
				sum[i % d] += a[i] - b[i];
			}
			for (int p = 1; p <= LIM; p += d) {
				if (p >= m && is_prime[p]) {
					int x = ran(2, p - 1);
					int r0 = qpow(x, (p - 1) / d, p);
					int r = 1;
					for (int i = 0; i < d; ++i, r = 1ll * r * r0 % p) {
						if (2 <= r && r < p - 1) {
							int s = 0, pw = 1;
							for (int k = 0; k < d; ++k) {
								s = (s + 1ll * pw * sum[k]) % p;
								pw = 1ll * pw * r % p;
							}
							if (s == 0) {
								std::cout << p << " " << r << "\n";
								return 0;
							}
						}
					}
				}
			}
		}
		++d;
	}
	std::cout << "hzkmd\n";
}