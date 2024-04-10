#include <bits/stdc++.h>

long long exgcd(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	long long g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	long long k;
	std::cin >> n >> m >> k;
	int lim = std::max(n, m) * 2;
	std::vector<int> a(lim, -1), b(lim, -1);
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		a[x] = i;
	}
	for (int i = 0; i < m; ++i) {
		int x;
		std::cin >> x;
		--x;
		b[x] = i;
	}
	
	long long _x, _y;
	int g = exgcd(n, m, _x, _y);
	long long ng = n / g, mg = m / g;
	std::vector<long long> x(lim), y(lim);
	for (int i = 0; i < lim; ++i) {
		if (a[i] != -1 && b[i] != -1 && (b[i] - a[i]) % g == 0) {
			x[i] = _x * (b[i] - a[i]) / g;
			y[i] = _y * (a[i] - b[i]) / g;
			long long t;
			if (x[i] < 0) {
				t = (-x[i] - 1) / mg + 1;
			} else {
				t = -x[i] / mg;
			}
			if (y[i] < 0) {
				t = std::max(t, (-y[i] - 1) / ng + 1);
			} else {
				t = std::max(t, -y[i] / ng);
			}
			x[i] += t * mg;
			y[i] += t * ng;
		}
	}

	auto check = [&](long long mid) {
		long long res = mid;
		for (int i = 0; i < lim; ++i) {
			if (a[i] != -1 && b[i] != -1 && (b[i] - a[i]) % g == 0) {
				long long v = a[i] + x[i] * n;
				if (v < mid) {
					res -= (mid - v - 1) / (n * mg) + 1;
				}
			}
		}
		return res >= k;
	};

	long long l = 0, r = 1e18, ans = -1;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	std::cout << ans << "\n";
}