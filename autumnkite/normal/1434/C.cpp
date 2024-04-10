#include <bits/stdc++.h>

long long a, b, c, d;

void solve() {
	std::cin >> a >> b >> c >> d;
	d = std::min(d, c);
	long long t = std::min((a + d * b - 1) / (d * b), c / d + 1);
	long long s = a * t - t * (t - 1) / 2 * d * b;
	if (t < c / d + 1) {
		std::cout << s << std::endl;
		return;
	}
	long long m = t * d * b - a - (d - c % d) * b;
	if (m < 0) {
		std::cout << -1 << std::endl;
	} else {
		std::cout << s << std::endl;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}