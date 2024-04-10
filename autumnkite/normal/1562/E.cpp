#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    auto exkmp = [&](std::string s) {
        int n = s.size();
        std::vector<int> z(n);
        z[0] = n;
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            z[i] = std::max(0, std::min(z[i - l], r - i));
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
            if (i + z[i] > r) {
                r = i + z[i];
                l = i;
            }
        }
        return z;
    };

    std::vector<int> f(n);
    for (int i = n - 1; i >= 0; --i) {
        auto z = exkmp(s.substr(i));
        f[i] = n - i;
        for (int j = i + 1; j < n; ++j) {
            int len = z[j - i];
            if (j + len < n && s[j + len] > s[i + len]) {
                f[i] = std::max(f[i], f[j] + n - i - len);
            }
        }
    }
    std::cout << *std::max_element(f.begin(), f.end()) << "\n";
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