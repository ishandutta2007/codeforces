#include <bits/stdc++.h>

int solve(int a, int n, int p);

int solve1(int a, int n, int p) {
	if (1ll * a * n < p) {
		return std::max(a, p - a * n);
	}
	return solve(a, n, p);
}

int solve(int a, int n, int p) {
	if (1ll * a * n < p) {
		return a;
	}
	return solve1(p % a, 1ll * (n - p / a + 1) * a / p, a);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int T;
	std::cin >> T;
	while (T--) {
		int a, n, p, d;
		std::cin >> a >> n >> p >> d;
		a %= p;
		std::cout << (solve(a, n, p) <= d ? "YES\n" : "NO\n");
	}
}