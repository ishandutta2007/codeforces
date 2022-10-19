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
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        int mn[n][m];
        int mx[n][m];
        mn[0][0] = mx[0][0] = a[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    mn[i][j] = mn[i][j - 1] + a[i][j];
                    mx[i][j] = mx[i][j - 1] + a[i][j];
                } else if (j == 0) {
                    mn[i][j] = mn[i - 1][j] + a[i][j];
                    mx[i][j] = mx[i - 1][j] + a[i][j];
                } else {
                    mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + a[i][j];
                    mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + a[i][j];
                }
            }
        }
        if (mn[n - 1][m - 1] <= 0 && mx[n - 1][m - 1] >= 0 && (n + m - 1) % 2 == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}