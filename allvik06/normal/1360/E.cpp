#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <vector <int>> a(n, vector <int> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }
        }
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 0) continue;
                if (i == n - 1 || j == n - 1) continue;
                if (a[i + 1][j] == 0 && a[i][j + 1] == 0) flag = false;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}