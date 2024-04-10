#include <bits/stdc++.h>

using namespace std;

char f(char a) {
    if (a == '9') {
        return '1';
    }
    return '9';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n = 9;
        vector <vector <char>> a(n, vector <char> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        a[0][0] = f(a[0][0]);
        a[3][1] = f(a[3][1]);
        a[6][2] = f(a[6][2]);
        a[1][3] = f(a[1][3]);
        a[4][4] = f(a[4][4]);
        a[7][5] = f(a[7][5]);
        a[2][6] = f(a[2][6]);
        a[5][7] = f(a[5][7]);
        a[8][8] = f(a[8][8]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
}