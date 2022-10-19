#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    for (int i = 0; i < 2 * k; ++i) {
        int x;
        cin >> x >> x;
    }
    for (int i = 0; i < m - 1; ++i) {
        s += "L";
    }
    for (int j = 0; j < n - 1; ++j) {
        s += "U";
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (i % 2 == 0) {
                if (j == 0) {
                    s += "D";
                }
                else {
                    s += "R";
                }
            }
            else {
                if (j == 0) {
                    s += "D";
                }
                else {
                    s += "L";
                }
            }
        }
    }
    cout << s.size() << "\n";
    cout << s;
    return 0;
}