#include <bits/stdc++.h>

const unsigned long long B = 19260817;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
    }

    std::vector<unsigned long long> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * B;
    }
    
    long long ans = 0;

    auto solve = [&](auto self, int l, int r) -> void {
        if (l + 1 == r) {
            return;
        }
        int mid = (l + r + 1) >> 1;
        std::vector<int> sta;
        unsigned long long ha = 0;
        std::map<unsigned long long, int> mp;
        for (int i = mid - 1; i >= l; --i) {
            if (sta.empty() || a[i] != sta.back()) {
                ha += pw[sta.size()] * (a[i] + 1);
                sta.push_back(a[i]);
            } else {
                sta.pop_back();
                ha -= pw[sta.size()] * (a[i] + 1);
            }
            ++mp[ha];
        }
        sta.clear();
        ha = 0;
        for (int i = mid; i < r; ++i) {
            if (sta.empty() || a[i] != sta.back()) {
                ha += pw[sta.size()] * (a[i] + 1);
                sta.push_back(a[i]);
            } else {
                sta.pop_back();
                ha -= pw[sta.size()] * (a[i] + 1);
            }
            ans += mp[ha];
        }
        self(self, l, mid);
        self(self, mid, r);
    };

    solve(solve, 0, n);
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