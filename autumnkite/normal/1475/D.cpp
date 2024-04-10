#include <bits/stdc++.h>

const int N = 200005;

int n, m;
int w[N];
int na, nb;
long long a[N], b[N];

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> w[i];
	}
	na = 0, nb = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		std::cin >> x;
		if (x == 1) {
			a[++na] = w[i];
		} else {
			b[++nb] = w[i];
		}
	}
	std::sort(a + 1, a + 1 + na, std::greater<long long>());
	std::sort(b + 1, b + 1 + nb, std::greater<long long>());
	for (int i = 1; i <= na; ++i) {
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= nb; ++i) {
		b[i] += b[i - 1];
	}
	if (a[na] + b[nb] < m) {
		std::cout << -1 << "\n";
		return;
	}
	int ans = na + nb * 2;
	int j = nb;
	for (int i = 0; i <= na; ++i) {
		while (j && a[i] + b[j - 1] >= m) {
			--j;
		}
		if (a[i] + b[j] >= m) {
			ans = std::min(ans, i + j * 2);
		}
	}
	std::cout << ans << "\n";
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