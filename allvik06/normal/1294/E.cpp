#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int b[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if ((a[i][j] - j - 1) % m != 0 || a[i][j] > m * n) {
                b[i][j] = -1;
            }
            else {
                if (a[i][j] <= m * i + (j + 1)) {
                    b[i][j] = (m * i + (j + 1) - a[i][j]) / m;
                }
                else {
                    b[i][j] = i;
                    b[i][j] += (m * (n - 1) + j + 1 - a[i][j]) / m + 1;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        vector <int> now(n);
        for (int j = 0; j < n; ++j) {
            if (b[j][i] == -1) {
                continue;
            }
            now[b[j][i]]++;
        }
        int ans = n;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, j + n - now[j]);
        }
        res += ans;
    }
    cout << res;
    return 0;
}