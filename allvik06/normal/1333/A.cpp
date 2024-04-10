#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m - 1; ++i) {
            cout << "W";
        }
        cout << "B\n";
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << "B";
            }
            cout << "\n";
        }
    }
    return 0;
}