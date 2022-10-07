#include <bits/stdc++.h>

long long calc(long long n) {
	long long res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

void solve() {
	long long n;
	std::cin >> n;
	while (std::__gcd(n, calc(n)) == 1) {
		++n;
	}
	std::cout << n << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}