#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	long long ans = std::numeric_limits<long long>::min();
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0 && 1ll * (i + 1) * (j + 1) > ans; --j) {
			ans = std::max(ans, 1ll * (i + 1) * (j + 1) - 1ll * k * (a[i] | a[j]));
		}
	}
	std::cout << ans << "\n";
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