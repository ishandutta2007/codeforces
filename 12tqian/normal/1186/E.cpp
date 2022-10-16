#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			g[i][j] = s[j] - '0';
		}
	}
	vector<vector<int>> p(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		int run = 0;
		for (int j = 0; j < m; ++j) {
			run += g[i][j];
			p[i][j] = run + (i ? p[i - 1][j] : 0);
		}
	}
	auto rect = [&](int xl, int xr, int yl, int yr) {
		int ret = p[xr][yr];
		ret -= (xl ? p[xl - 1][yr] : 0);
		ret -= (yl ? p[xr][yl - 1] : 0);
		ret += (xl * yl ? p[xl - 1][yl - 1] : 0);
		return ret;
	};	
	auto bits = [&](int x) {
		return __builtin_popcount(x);
	};
	auto odd = [&](int x) { // does it have odd bit count
		return (bits(x) & 1);
	};
	auto count = [&](int l, int r) { // odd bit count in range
		const int L = 5;
		int ans = 0;
		if (r - l + 1 <= L) {
			for (int i = l; i <= r; ++i) {
				ans += odd(i);
			}
		} else {
			if (l & 1) {
				ans += odd(l);
				++l;
			}
			if ((r & 1) ^ 1) {
				ans += odd(r);
				--r;
			}
			l >>= 1;
			r >>= 1;
			ans += r - l + 1;
		}
		return ans;
	};
	while (q--) {
		int xl, yl, xr, yr;
		cin >> xl >> yl >> xr >> yr;
		--xl, --yl, --xr, --yr;
		array<int, 4> bounds = {xl, xr, yl, yr};
		auto check = [&](int xl, int xr, int yl, int yr) {
			if (xl > xr || yl > yr) {
				return false;
			}
			return bounds[0] <= xl && xr <= bounds[1] && bounds[2] <= yl && yr <= bounds[3];
		};
		auto fdiv = [&](int x, int y) {
			return x / y;
		};
		auto cdiv = [&](int x, int y) {
			return (x + y - 1) / y;
		};
		auto range = [&](int l, int r) {
			return array<long long, 2>{r - l + 1 - count(l, r), count(l, r)};
		};
		auto value = [&](int x, int y) {
			return ((bits(x) + bits(y)) & 1);
		};
		auto bound = [&](int x, int n, int t) {
			if (t == 0) {
				return fdiv(x + 1, n) * n - 1;
			} else {
				return cdiv(x, n) * n;
			}
		};
		auto shift = [&](int x, int n, int t) {
			if (t == 0) {
				return fdiv(x, n) * n;
			} else {
				return cdiv(x + 1, n) * n - 1;
			}
		};
		auto full = [&](int xl, int xr, int yl, int yr) { // inner rectangle
			if (!check(xl, xr, yl, yr)) {
				return 0LL;
			}
			long long ans = 0;
			auto x = range(xl / n, xr / n);
			auto y = range(yl / m, yr / m);
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					int sum;
					if ((i + j) & 1) {
						sum = n * m - p[n - 1][m - 1];
					} else {
						sum = p[n - 1][m - 1];
					}
					ans += x[i] * y[j] * sum;
				}
			}
			return ans;
		};
		auto small = [&](int xl, int xr, int yl, int yr) {
			if (!check(xl, xr, yl, yr)) {
				return 0;
			}
			int parity = value(xl / n, yl / m);
			xl %= n;
			xr %= n;
			yl %= m;
			yr %= m;
			int ans = rect(xl, xr, yl, yr);
			if (parity & 1) {
				ans = (xr - xl + 1) * (yr - yl + 1) - ans;
			}
			return ans;
		};	
		auto horizontal_strip = [&](int xl, int xr, int yl, int yr) {
			if (xl / n != xr / n || !check(xl, xr, yl, yr)) {
				return 0LL;
			}
			auto v = range(yl / m, yr / m);
			int parity = bits(xl / n);
			xl %= n;
			xr %= n;
			int full = rect(xl, xr, 0, m - 1);
			long long ans = 0;
			for (int i = 0; i < 2; ++i) {
				if (((parity + i) & 1)) {
					ans += v[i] * ((xr - xl + 1) * m - full);
				} else {
					ans += v[i] * full;
				}
			}
			return ans;
		};
		auto vertical_strip = [&](int xl, int xr, int yl, int yr) {
			if (yl / m != yr / m || !check(xl, xr, yl, yr)) {
				return 0LL;
			}
			auto v = range(xl / n, xr / n);
			int parity = bits(yl / m);
			yl %= m;
			yr %= m;
			int full = rect(0, n - 1, yl, yr);
			long long ans = 0;
			for (int i = 0; i < 2; ++i) {
				if ((parity + i) & 1) {
					ans += v[i] * (n * (yr - yl + 1) - full);
				} else {
					ans += v[i] * full;
				}
			}
			return ans;
		};
		array<int, 2> lx = {xl, shift(xl, n, 1)};
		array<int, 2> rx = {shift(xr, n, 0), xr};
		array<int, 2> ly = {yl, shift(yl, m, 1)};
		array<int, 2> ry = {shift(yr, m, 0), yr};
		long long ans = 0;
		if (xl / n == xr / n && yl / m == yr / m) {
			ans += small(xl, xr, yl, yr);
		} else if (xl / n == xr / n) {
			if (ly[0] % m != 0) {
				ans += small(xl, xr, ly[0], ly[1]);
			}
			if (ry[1] % m != m - 1) {
				ans += small(xl, xr, ry[0], ry[1]);
			}
			ans += horizontal_strip(xl, xr, bound(yl, m, 1), bound(yr, m, 0));
		} else if (yl / m == yr / m) {
			if (lx[0] % n != 0) {
				ans += small(lx[0], lx[1], yl, yr);
			}
			if (rx[1] % n != n - 1) {
				ans += small(rx[0], rx[1], yl, yr);
			}
			ans += vertical_strip(bound(xl, n, 1), bound(xr, n, 0), yl, yr);
		} else {
			ans += full(bound(xl, n, 1), bound(xr, n, 0), bound(yl, m, 1), bound(yr, m, 0));
			if (lx[0] % n != 0) {
				ans += horizontal_strip(lx[0], lx[1], bound(yl, m, 1), bound(yr, m, 0));
			}
			if (rx[1] % n != n - 1) {
				ans += horizontal_strip(rx[0], rx[1], bound(yl, m, 1), bound(yr, m, 0));
			}
			if (ly[0] % m != 0) {
				ans += vertical_strip(bound(xl, n, 1), bound(xr, n, 0), ly[0], ly[1]);
			}
			if (ry[1] % m != m - 1) {
				ans += vertical_strip(bound(xl, n, 1), bound(xr, n, 0), ry[0], ry[1]);
			}
			if (lx[0] % n != 0 && ly[0] % m != 0) {
				ans += small(lx[0], lx[1], ly[0], ly[1]);
			}
			if (lx[0] % n != 0 && ry[1] % m != m - 1) {
				ans += small(lx[0], lx[1], ry[0], ry[1]);
			}
			if (rx[1] % n != n - 1 && ly[0] % m != 0) {
				ans += small(rx[0], rx[1], ly[0], ly[1]);
			}
			if (rx[1] % n != n - 1 && ry[1] % m != m - 1) {
				ans += small(rx[0], rx[1], ry[0], ry[1]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}