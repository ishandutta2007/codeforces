#include <bits/stdc++.h>

long long INF = 0x3f3f3f3f3f3f3f3fll;

long long n;

int mu[61];
std::vector<long long> pw[61];

long long qpow(int a, int b) {
	long long s = 1;
	for (int i = 1; i <= b; ++i) {
		if (s < INF / a) {
			s *= a;
		} else {
			return INF;
		}
	}
	return s;
}

void init() {
	mu[1] = 1;
	for (int i = 1; i <= 60; ++i) {
		for (int j = i + i; j <= 60; j += i) {
			mu[j] -= mu[i];
		}
	}
	for (int i = 3; i <= 60; ++i) {
		for (int j = 1; ; ++j) {
			long long t = qpow(j, i);
			if (t < INF) {
				pw[i].push_back(t);
			} else {
				break;
			}
		}
	}
}

long long count(int x) {
	if (x >= 3) {
		return std::upper_bound(pw[x].begin(), pw[x].end(), n) - pw[x].begin() - 1;
	}
	if (x == 1) {
		return n - 1;
	}
	long long l = 1, r = n, ans = 0;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (mid < INF / mid && mid * mid <= n) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans - 1;
}

void solve() {
	std::cin >> n;
	long long ans = 0;
	for (int i = 1; i <= 60; ++i) {
		ans += mu[i] * count(i);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init();

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}