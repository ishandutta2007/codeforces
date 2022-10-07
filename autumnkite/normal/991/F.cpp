#include <bits/stdc++.h>

long long n;
std::string ans;
std::map<long long, std::string> mp;

std::string toString(long long x) {
	if (!x) {
		return "0";
	}
	std::string res;
	while (x) {
		res += x % 10 ^ '0';
		x /= 10;
	}
	std::reverse(res.begin(), res.end());
	return res;
}

void update(std::string &ans, const std::string &s) {
	if (s.size() < ans.size()) {
		ans = s;
	}
}

int main() {
	std::cin >> n;
	ans = toString(n);
	for (int i = 2; 1ll * i * i <= n; ++i) {
		long long v = 1ll * i * i;
		for (int j = 2; v <= n; ++j, v *= i) {
			std::string tmp = toString(i) + "^" + toString(j);
			if (!mp.count(v)) {
				mp[v] = tmp;
			} else {
				update(mp[v], tmp);
			}
			if (v == n) {
				update(ans, tmp);
			}
			if (n % v == 0) {
				update(ans, tmp + "*" + toString(n / v));
				if (mp.count(n / v)) {
					update(ans, tmp + "*" + mp[n / v]);
				}
			}
			update(ans, tmp + "+" + toString(n - v));
			if (mp.count(n - v)) {
				update(ans, tmp + "+" + mp[n - v]);
			}
			update(ans, tmp + "*" + toString(n / v) + "+" + toString(n % v));
		}
	}
	if ((int)ans.size() <= 9) {
		std::cout << ans << std::endl;
		return 0;
	}
	for (int a = 2; a <= 9; ++a) {
		long long s1 = a;
		for (int b = 2; b <= 9; ++b) {
			s1 *= a;
			for (int c = 2; c <= 9; ++c) {
				long long s2 = c;
				for (int d = 2; d <= 9; ++d) {
					s2 *= c;
					for (int e = 1; e <= 9; ++e) {
						if (s1 * s2 + e == n) {
							update(ans, toString(a) + "^" + toString(b) + "*" + toString(c) + "^" + toString(d) + "+" + toString(e));
						}
						if (s1 * s2 * e == n) {
							update(ans, toString(a) + "^" + toString(b) + "*" + toString(c) + "^" + toString(d) + "*" + toString(e));
						}
						if (s1 * e + s2 == n) {
							update(ans, toString(a) + "^" + toString(b) + "*" + toString(e) + "+" + toString(c) + "^" + toString(d));
						}
					}
				}
			}
		}
	}
	std::cout << ans << std::endl;
}