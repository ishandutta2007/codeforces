#include <bits/stdc++.h>

const int N = 100005;

int n, a[N][2];
long long f[N][3];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i][0];
	}
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i][1];
	}
	f[0][0] = f[0][1] = f[0][2] = 0;
	for (int i = 1; i <= n; ++i) {
		f[i][0] = std::max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
		f[i][1] = std::max(f[i - 1][0], f[i - 1][2]) + a[i][0];
		f[i][2] = std::max(f[i - 1][0], f[i - 1][1]) + a[i][1];
	}
	std::cout << std::max({f[n][0], f[n][1], f[n][2]}) << "\n";
}