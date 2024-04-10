#include <bits/stdc++.h>

void solve() {
    std::string a;
    std::cin >> a;
    std::string p = "ANOT";
    long long max = 0;
    std::string ans = a;
    do {
        int cnt[4] = {};
        long long sum = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            int v = 0;
            while (p[v] != a[i]) {
                ++v;
            }
            for (int j = v + 1; j < 4; ++j) {
                sum += cnt[j];
            }
            ++cnt[v];
        }
        if (sum > max) {
            max = sum;
            ans.clear();
            for (int i = 0; i < 4; ++i) {
                ans += std::string(cnt[i], p[i]);
            }
        }
    } while (std::next_permutation(p.begin(), p.end()));
    std::cout << ans << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}