#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m = (n + 1) / 3;
    vector<pair<int, int>> res;
    for (int i = 1; i <= m - 1; i++) {
        res.emplace_back(i, m - i);
    }
    for (int i = 1; i <= m; i++) {
        res.emplace_back(i + m - 1, m + 1 - i + m - 1);
    }

    for (int i = res.size() + 1; i <= n - m; i++) {
        res.emplace_back(i, i);
    }

    cout << res.size() << '\n';
    for (auto e : res) {
        cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}