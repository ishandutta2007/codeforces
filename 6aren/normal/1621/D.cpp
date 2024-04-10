#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> a(2 * n, vector<int>(2 * n));
        long long sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                cin >> a[i][j];
                if (i >= n && j >= n) sum += a[i][j];
            }
        }
        int mn = 0;
        mn = min({a[0][n], a[0][2*n-1], a[n - 1][n], a[n-1][2*n-1], a[n][0], a[n][n - 1], a[2*n-1][0], a[2*n-1][n - 1]});
        cout << sum + mn << '\n';
    }
    return 0;
}