#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << -1;
        return 0;
    }
    vector <vector <int>> a(n, vector <int> (n));
    a[0][0] = n * n - 9 + 1;
    a[0][1] = n * n - 9 + 3;
    a[0][2] = n * n - 9 + 4;
    a[1][0] = n * n - 9 + 8;
    a[1][1] = n * n - 9 + 2;
    a[1][2] = n * n - 9 + 5;
    a[2][0] = n * n - 9 + 7;
    a[2][1] = n * n - 9 + 6;
    a[2][2] = n * n - 9 + 9;
    int now = 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 3; j < n; ++j) {
                a[j][i] = now;
                ++now;
            }
        }
        else {
            for (int j = n - 1; j >= 3; --j) {
                a[j][i] = now;
                ++now;
            }
        }
    }
    for (int i = 2; i >= 0; --i) {
        if (i % 2 == 0) {
            for (int j = n - 1; j >= 3; --j) {
                a[i][j] = now;
                ++now;
            }
        }
        else {
            for (int j = 3; j < n; ++j) {
                a[i][j] = now;
                ++now;
            }
        }
    }
    for (auto i : a) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}