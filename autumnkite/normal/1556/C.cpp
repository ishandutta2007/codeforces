#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + (i & 1 ? -a[i] : a[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i += 2) {
        long long mn = INF;
        for (int j = i + 1; j < n; j += 2) {
            long long l = std::max(sum[i], sum[j + 1]), r = std::min(sum[i + 1], sum[j]);
            r = std::min(r, mn);
            ans += std::max(r - l + 1, 0ll);
            ans -= j == i + 1;
            mn = std::min(mn, sum[j + 1]);
        }
    }
    std::cout << ans << "\n";
}