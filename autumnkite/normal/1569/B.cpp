#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::string> a(n, std::string(n, '='));
    std::vector<int> p;
    for (int i = 0; i < n; ++i) {
        a[i][i] = 'X';
        if (s[i] == '2') {
            p.push_back(i);
        }
    }
    if ((int)p.size() == 1 || (int)p.size() == 2) {
        std::cout << "NO\n";
        return;
    }
    for (int i = 0; i < (int)p.size(); ++i) {
        a[p[i]][p[(i + 1) % p.size()]] = '+';
        a[p[(i + 1) % p.size()]][p[i]] = '-';
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << "\n";
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