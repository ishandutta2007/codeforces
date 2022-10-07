#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        std::string a;
        std::cin >> a;
        int cnt[3] = {};
        for (char c : a) {
            ++cnt[c - 'A'];
        }
        if (cnt[1] == cnt[0] + cnt[2]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}