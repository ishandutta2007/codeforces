#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int m = *std::max_element(a.begin(), a.end());
    int LG = std::__lg(m) + 1;
    m = 1 << LG;

    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] ^ a[i];
    }

    int ans = 0;
    for (int k = LG - 1; k >= 0; --k) {
        std::vector<int> h(1 << (LG - k));
        std::vector<std::vector<int>> p(1 << (LG - k));
        int s = 0, l = 0;
        for (int i = 0; i <= n; ++i) {
            int v = sum[i] >> k;
            if (h[v] < (int)p[v].size()) {
                ans = std::max(ans, i - p[v][h[v]]);
            }
            if (i < n) {
                s += !(a[i] >> k & 1);
                p[v].push_back(i);
                while (l <= i && s > 0) {
                    s -= !(a[l] >> k & 1);
                    ++h[sum[l] >> k];
                    ++l;
                }
            }
        }
    }
    std::cout << ans << "\n";
}