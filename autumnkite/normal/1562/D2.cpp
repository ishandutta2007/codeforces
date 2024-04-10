#include <bits/stdc++.h>

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + ((s[i] == '+') ^ (i & 1) ? 1 : -1);
    }
    std::map<int, std::set<int>> S;
    for (int i = 0; i < n; ++i) {
        S[sum[i] + sum[i + 1]].insert(i);
    }
    auto solve = [&](int l, int r) {
        return *S[sum[l] + sum[r]].lower_bound(l);
    };
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l;
        if ((r - l) & 1) {
            std::cout << 1 << "\n";
            std::cout << solve(l, r) + 1 << "\n";
        } else if (sum[r] - sum[l] == 0) {
            std::cout << 0 << "\n";
        } else {
            std::cout << 2 << "\n";
            std::cout << l + 1 << " " << solve(l + 1, r) + 1 << "\n";
        }
    }
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