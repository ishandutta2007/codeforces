#include <bits/stdc++.h>

const int P = 998244353, Inv2 = (P + 1) / 2;

std::vector<int> fac, inv;

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

void init(int n) {
	fac.resize(n + 1), inv.resize(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[n] = qpow(fac[n], P - 2);
	for (int i = n; i >= 1; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
}

int C(int n, int m) {
	if (m < 0 || m > n) {
		return 0;
	}
	return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}

class binom_prefix {
	int n, t;
	int s;

	void advance_n(int delta) {
		if (delta > 0) {
			for (int i = 0; i < delta; ++i) {
				s = (2ll * s + P - C(n, t)) % P;
				++n;
			}
		} else if (delta < 0) {
			for (int i = delta; i < 0; ++i) {
				--n;
				s = 1ll * (s + C(n, t)) * Inv2 % P;
			}
		}
	}

	void advance_t(int delta) {
		if (delta > 0) {
			for (int i = 0; i < delta; ++i) {
				++t;
				s = (s + C(n, t)) % P;
			}
		} else if (delta < 0) {
			for (int i = delta; i < 0; ++i) {
				s = (s + P - C(n, t)) % P;
				--t;
			}
		}
	}

public:
	binom_prefix() : n(0), t(0), s(1) {}

	int operator()(int _n, int _t) {
		if (_t < 0) {
			return 0;
		}
		_t = std::min(_t, _n);
		advance_n(_n - n);
		advance_t(_t - t);
		return s;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::string s;
	std::cin >> s;

	auto value = [&](int i) {
		if (s[i] == '?') {
			return 0;
		} else if (s[i] == 'b') {
			return i & 1 ? 1 : -1;
		} else {
			return i & 1 ? -1 : 1;
		}
	};

	init(n);

	int sum = 0, cnt = 0;

	auto add = [&](int v, int d) {
		sum += v * d;
		cnt += (!v) * d;
	};
	for (int i = 0; i < n; ++i) {
		add(value(i), 1);
	}

	binom_prefix f;

	auto get_ans = [&]() -> int {
		if (cnt <= 2) {
			int ans = 0;
			for (int i = 0; i <= cnt; ++i) {
				int now = abs(sum + 2 * i - cnt);
				if (now % 4 == 0) {
					ans = (ans + 1ll * (now / 4) * C(cnt, i)) % P;
				}
			}
			return ans;
		}
		int t = (cnt - sum) / 2;
		return (1ll * (P + t) * (f(cnt - 1, t) + P - qpow(2, cnt - 2)) + 
		        1ll * (P - cnt) * (f(cnt - 2, t - 1) + P - qpow(2, cnt - 3))) % P;
	};

	std::cout << 1ll * get_ans() * qpow(2, P - cnt) % P << "\n";
	while (q--) {
		int x;
		char c;
		std::cin >> x >> c;
		--x;
		add(value(x), -1);
		s[x] = c;
		add(value(x), 1);
		std::cout << 1ll * get_ans() * qpow(2, P - cnt) % P << "\n";
	}
}