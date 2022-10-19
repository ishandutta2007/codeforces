#include <bits/stdc++.h>

using namespace std;
#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <vector <int>> str(n, vector <int> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> str[i][j];
            }
        }
        vector <vector <int>> st(m, vector <int> (n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> st[i][j];
            }
        }
        vector <int> a(n * m + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[str[i][j]] = i;
            }
        }
        vector <int> ord;
        for (int i = 0; i < n; ++i) {
            ord.push_back(a[st[0][i]]);
        }
        for (int i : ord) {
            for (int j : str[i]) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
}