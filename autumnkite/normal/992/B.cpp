#include <bits/stdc++.h>

int l, r, x, y;
int ans;

bool check(long long a) {
	long long b = y / a * x;
	return l <= a && a <= r && l <= b && b <= r && std::__gcd(a, b) == x;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> l >> r >> x >> y;
	for (int i = 1; i * i <= y; ++i) {
		if (y % i == 0) {
			ans += check(i);
			if (i * i < y) {
				ans += check(y / i);
			}
		}
	}
	std::cout << ans << "\n";
}