#include <bits/stdc++.h>

const int P = 1000000007, I2 = (P + 1) / 2;

struct Segment {
	int l, r, op;

	bool operator<(const Segment &rhs) const {
		return r < rhs.r || (r == rhs.r && l > rhs.l);
	}
};

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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int L, n, m;
	std::cin >> L >> n >> m;
	std::vector<Segment> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].l >> a[i].r;
		--a[i].l;
		a[i].op = 0;
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i].l >> b[i].r;
		--b[i].l;
		b[i].op = 1;
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	for (int i = 1; i < n; ++i) {
		a[i].l = std::max(a[i].l, a[i - 1].l);
	}
	for (int i = 1; i < m; ++i) {
		b[i].l = std::max(b[i].l, b[i - 1].l);
	}
	std::vector<Segment> c(n + m);
	std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

	std::vector<int> f(n + m);
	int ans = 1;
	std::vector<int> s(n + m + 1);
	std::vector<std::vector<int>> si(2, std::vector<int>(n + m + 1));
	for (int i = 0; i < n + m; ++i) {
		int p = std::upper_bound(c.begin(), c.end(), c[i].l, [&](int x, Segment t) {
			return x < t.r;
		}) - c.begin();
		int t1 = P - qpow(I2, c[i].r - c[i].l), t2 = P - qpow(I2, c[i].r);
		f[i] = (1ll * (s[p] + 1) * t1 + 1ll * (P + si[c[i].op][i] - si[c[i].op][p]) * t2) % P;
		s[i + 1] = (s[i] + f[i]) % P;
		si[c[i].op][i + 1] = (si[c[i].op][i] + 1ll * f[i] * qpow(2, c[i].r)) % P;
		si[!c[i].op][i + 1] = si[!c[i].op][i];
		ans = (ans + f[i]) % P;
	}

	std::cout << 1ll * ans * qpow(2, L) % P << "\n";
}