#include <bits/stdc++.h>

const int N = 400000, LG = 18;
const int P = 998244353;

int fac[N + 1], inv[N + 1];

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

void init() {
	fac[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[N] = qpow(fac[N], P - 2);
	for (int i = N; i >= 1; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
}

int C(int n, int m) {
	if (m < 0 || m > n) {
		return 0;
	}
	return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}

int c[N + 1];

void add(int x, int v) {
	for (; x <= N; x += x & -x) {
		c[x] += v;
	}
}

int query(int v) {
	int x = 0;
	for (int i = LG - 1; i >= 0; --i) {
		if (x + (1 << i) <= N && c[x + (1 << i)] < v) {
			x += 1 << i;
			v -= c[x];
		}
	}
	return x + 1;
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> x(m), y(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> x[i] >> y[i];
	}
	std::vector<int> p(m);
	for (int i = m - 1; i >= 0; --i) {
		p[i] = query(y[i]);
		add(p[i], -1);
	}
	for (int i : p) {
		add(i, 1);
	}
	for (int i : x) {
		add(i, -1);
	}
	std::vector<int> id(m);
	std::iota(id.begin(), id.end(), 0);
	std::sort(id.begin(), id.end(), [&](int x, int y) {
		return p[x] < p[y];
	});
	int k = n - 1;
	for (int i = 0; i < m; ++i) {
		if (i + 1 < m && p[id[i]] + 1 == p[id[i + 1]]) {
			k -= id[i] > id[i + 1];
		} else {
			int t = query(p[id[i]] - i);
			k -= x[i] > t;
		}
	}
	for (int i : x) {
		add(i, 1);
	}
	std::cout << C(n + k, n) << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init();
	for (int i = 1; i <= N; ++i) {
		add(i, 1);
	}

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}