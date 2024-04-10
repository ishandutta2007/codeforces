#include <bits/stdc++.h>

using namespace std;

int a[55][55];
int b[55][55];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    vector < pair < int, int > > ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
                ans.push_back({i, j});
                b[i][j] = 1, b[i + 1][j] = 1, b[i][j + 1] = 1, b[i + 1][j + 1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != b[i][j]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto key : ans) cout << key.first << " " << key.second << '\n';
    return 0;
}