#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        --a[i];
    }
    if (n == k) {
        cout << -1;
        return 0;
    }
    vector <bool> t(n);
    for (int i : a) t[i] = true;
    int v;
    for (int i = 0; i < n; ++i) {
        if (!t[i]) v = i;
    }
    int f = -1, s = -1;
    for (int i = 0; i < n; ++i) {
        if (i == v) continue;
        if (f == -1 && t[i]) f = i;
        else if (s == -1 && t[i]) s = i;
    }
    for (int i = 0; i < n; ++i) {
        if (i == v) continue;
        if (f == -1) f = i;
        else if (s == -1) s = i;
    }
    vector <pair <int, int>> all = {{f + 1, v + 1}, {v + 1, s + 1}};
    for (int i = 0; i < n; ++i) {
        if (i == v || i == f || i == s) continue;
        all.emplace_back(i + 1, f + 1);
    }
    for (int i = 0; i < n; ++i) {
        if (i == f) continue;
        for (int j = i + 1; j < n && (int)all.size() < m; ++j) {
            if (j == f || (i == s && t[j]) || (j == s && t[i]) || (i == s && j == v) || (i == v && j == s)) continue;
            all.emplace_back(i + 1, j + 1);
        }
    }
    if ((int)all.size() == m) {
        for (auto i: all) {
            cout << i.first << " " << i.second << "\n";
        }
    } else cout << -1;
}