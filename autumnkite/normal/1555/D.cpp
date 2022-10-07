#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::string a;
    std::cin >> a;
    std::vector<std::vector<int>> sum(6, std::vector<int>(n + 1));
    std::string p = "abc";
    for (int k = 0; k < 6; ++k) {
        for (int i = 0; i < n; ++i) {
            sum[k][i + 1] = sum[k][i] + (a[i] != p[i % 3]);
        }
        std::next_permutation(p.begin(), p.end());
    }
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        --l;
        int ans = INF;
        for (int i = 0; i < 6; ++i) {
            ans = std::min(ans, sum[i][r] - sum[i][l]);
        }
        std::cout << ans << "\n";
    }
}