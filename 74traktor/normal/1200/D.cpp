#include <bits/stdc++.h>

using namespace std;

int a[2005][2005];
int row[2005];
int col[2005];
int pref_row[2005];
int pref_col[2005];
int pref[2005];
int pref_in_col[2005][2005];
int pref_in_row[2005][2005];
int ok1[2005][2005];
int ok2[2005][2005];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    char t;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t;
            if (t == 'B') a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) row[i] = 1, col[i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 1) row[i] = 0, col[j] = 0;
        }
    }
    //cout << "OK" << endl;
    for (int i = 1; i <= n; ++i) {
        pref_row[i] = pref_row[i - 1] + row[i];
        pref_col[i] = pref_col[i - 1] + col[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pref_in_col[i][j] = pref_in_col[i][j - 1] + a[j][i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pref_in_row[i][j] = pref_in_row[i][j - 1] + a[i][j];
        }
    }
    //cout << "OK" << endl;
    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pref[j] = pref[j - 1];
            if (pref_in_col[j][i - 1] == 0 && pref_in_col[j][n] - pref_in_col[j][i + k - 1] == 0) pref[j]++;
        }
        for (int j = 1; j + k - 1 <= n; ++j) {
            ok1[i][j] = pref[j + k - 1] - pref[j - 1];
        }
    }
    for (int j = 1; j + k - 1 <= n; j++) {
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1];
            if (pref_in_row[i][j - 1] == 0 && pref_in_row[i][n] - pref_in_row[i][j + k - 1] == 0) pref[i]++;
        }
        for (int i = 1; i + k - 1 <= n; ++i) {
            ok2[i][j] = pref[i + k - 1] - pref[i - 1];
        }
    }
    //cout << "OK" << endl;
    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j + k - 1 <= n; ++j) {
            int cur = pref_row[i - 1] + pref_col[j - 1] + (pref_row[n] - pref_row[i + k - 1]) + (pref_col[n] - pref_col[j + k - 1]);
            //if (i == 2 && j == 3) cout << cur << endl;
            cur += ok1[i][j] + ok2[i][j];
            //if (cur == 4) cout << i << " " << j << endl;
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
    return 0;
}