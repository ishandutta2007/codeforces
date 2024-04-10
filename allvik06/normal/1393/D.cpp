#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;
#define ll long long

int main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int dp1[n][m];
    int dp2[n][m];
    int up[n][m];
    int down[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0) up[i][j] = -1;
            else if (a[i][j] != a[i - 1][j]) up[i][j] = i - 1;
            else up[i][j] = up[i - 1][j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (i == n - 1) down[i][j] = n;
            else if (a[i][j] != a[i + 1][j]) down[i][j] = i + 1;
            else down[i][j] = down[i + 1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j == 0 || a[i][j] != a[i][j - 1]) dp1[i][j] = 1;
            else {
                dp1[i][j] = min(dp1[i][j - 1] + 1, min(i - up[i][j], down[i][j] - i));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (j == m - 1 || a[i][j] != a[i][j + 1]) dp2[i][j] = 1;
            else {
                dp2[i][j] = min(dp2[i][j + 1] + 1, min(i - up[i][j], down[i][j] - i));
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += min(dp1[i][j], dp2[i][j]);
        }
    }
    cout << ans;
}