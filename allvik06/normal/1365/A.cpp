#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <vector <int>> a(n, vector <int> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        int kolstr = 0, kolst = 0;
        for (int i = 0; i < n; ++i) {
            bool flag = true;
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) flag = false;
            }
            kolstr += flag;
        }
        for (int i = 0; i < m; ++i) {
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (a[j][i]) flag = false;
            }
            kolst += flag;
        }
        if (min(kolstr, kolst) % 2 == 0) cout << "Vivek\n";
        else cout << "Ashish\n";
    }
}