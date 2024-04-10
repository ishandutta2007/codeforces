#include <bits/stdc++.h>

const int N = 100005;

int n, m, x[N], fir[N], las[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		std::cin >> x[i];
	}
	std::fill(fir + 1, fir + 1 + n, m + 1);
	for (int i = m; i; --i) {
		fir[x[i]] = i;
	}
	std::fill(las + 1, las + 1 + n, 0);
	for (int i = 1; i <= m; ++i) {
		las[x[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = std::max(i - 1, 1); j <= std::min(i + 1, n); ++j) {
			if (las[i] < fir[j]) {
				++ans;
			}
		}
	}
	std::cout << ans << "\n";
}