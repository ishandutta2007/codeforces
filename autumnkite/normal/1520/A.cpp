#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<bool> vis(26);
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && s[j] == s[i]) {
            ++j;
        }
        if (vis[s[i] - 'A']) {
            std::cout << "NO\n";
            return;
        }
        vis[s[i] - 'A'] = true;
    }
    std::cout << "YES\n";
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