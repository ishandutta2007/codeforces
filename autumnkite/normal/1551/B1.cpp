#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    std::vector<int> cnt(26);
    for (char c : s) {
        ++cnt[c - 'a'];
    }
    int c1 = 0, c2 = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] >= 2) {
            ++c2;
        } else if (cnt[i] == 1) {
            ++c1;
        }
    }
    std::cout << c2 + c1 / 2 << "\n";
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