#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        std::string s;
        std::cin >> s;
        std::string t = s;
        std::sort(t.begin(), t.end());
        bool ok = true;
        for (int i = 0; i < (int)s.size(); ++i) {
            ok &= t[i] == 'a' + i;
        }
        int x = std::min_element(s.begin(), s.end()) - s.begin();
        for (int i = 0; i < x; ++i) {
            ok &= s[i] > s[i + 1];
        }
        for (int i = x; i + 1 < (int)s.size(); ++i) {
            ok &= s[i] < s[i + 1];
        }
        if (ok) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}