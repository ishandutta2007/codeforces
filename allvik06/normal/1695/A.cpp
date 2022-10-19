#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        int mx = -INF;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                mx = max(mx, a[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mx == a[i][j]) ans = max(i + 1, n - i) * max(j + 1, m - j);
            }
        }
        cout << ans << "\n";
    }
}