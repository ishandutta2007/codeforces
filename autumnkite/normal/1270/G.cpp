#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] = i - a[i];
    }
    std::vector<bool> vis(n);
    int x = 0;
    while (!vis[x]) {
        vis[x] = true;
        x = a[x];
    }
    std::vector<int> ans;
    int tmp = x;
    do {
        ans.push_back(x);
        x = a[x];
    } while (tmp != x);
    std::cout << ans.size() << "\n";
    for (int x : ans) {
        std::cout << x + 1 << " ";
    }
    std::cout << "\n";
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