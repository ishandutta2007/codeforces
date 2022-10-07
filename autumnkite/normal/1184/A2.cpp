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

	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::vector<int> f(n + 1);
	int ans = 0;
	for (int k = 1; k <= n; ++k) {
		int t = std::__gcd(k, n);
		if (t == k) {
			std::vector<int> c(k);
			for (int i = 0; i < n; ++i) {
				c[i % k] += s[i] - '0';
			}
			f[k] = 1;
			for (int i = 0; i < k; ++i) {
				f[k] &= !(c[i] & 1);
			}
		}
		ans += f[t];
	}
	std::cout << ans << "\n";
}