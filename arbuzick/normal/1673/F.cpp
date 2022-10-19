#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 32, k;
    vector<vector<int>> a = {{0}};
    for (int i = 0; i < 5; ++i) {
        for (auto &v : a) {
            auto v2 = v;
            reverse(v2.begin(), v2.end());
            for (auto val : v2) {
                v.push_back((1 << (i * 2)) + val);
            }
        }
        vector<vector<int>> a2(a[0].size(), vector<int>(a.size()));
        for (int x = 0; x < (int)a.size(); ++x) {
            for (int y = 0; y < (int)a[0].size(); ++y) {
                a2[y][x] = a[x][y];
            }
        }
        for (auto &v : a2) {
            auto v2 = v;
            reverse(v2.begin(), v2.end());
            for (auto val : v2) {
                v.push_back((1 << (i * 2 + 1)) + val);
            }
        }
        a = a2;
    }
    vector<int> pos(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pos[a[i][j]] = i * n + j;
        }
    }
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < n; ++j) {
            cout << (a[i][j] ^ a[i][j + 1]) << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (a[i][j] ^ a[i + 1][j]) << ' ';
        }
        cout << endl;
    }
    int nw = 0;
    while (k--) {
        int x;
        cin >> x;
        nw ^= x;
        cout << pos[nw] / 32 + 1 << ' ' << pos[nw] % 32 + 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}