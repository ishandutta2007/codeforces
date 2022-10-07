#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'U') {
                s[i] = 'D';
            } else if (s[i] == 'D') {
                s[i] = 'U';
            }
        }
        std::cout << s << "\n";
    }
}