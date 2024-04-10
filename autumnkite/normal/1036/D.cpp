#include <bits/stdc++.h>

const int N = 300005;

int n, m;
long long a[N], b[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		a[i] += a[i - 1];
	}
	std::cin >> m;
	for (int i = 1; i <= m; ++i) {
		std::cin >> b[i];
		b[i] += b[i - 1];
	}

	if (a[n] != b[m]) {
		std::cout << -1 << "\n";
		return 0;
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int p = std::lower_bound(b + 1, b + 1 + m, a[i]) - b;
		if (b[p] == a[i]) {
			++ans;
		}
	}
	std::cout << ans << "\n";
}