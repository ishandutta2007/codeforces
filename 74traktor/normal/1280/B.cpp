#include<bits/stdc++.h>

using namespace std;

char a[65][65];
int pref[65][65];
int col[65][65];
int row[65][65];
int mx[65];

void solve() {
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'A') cnt++;
            col[i][j] = col[i - 1][j];
            row[i][j] = row[i][j - 1];
            if (a[i][j] == 'P') col[i][j]++, row[i][j]++;
        }
    }
    if (cnt == 0) {
        cout << "MORTAL" << '\n';
        return;
    }
    if (cnt == n * m) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if (a[i][j] == 'P') pref[i][j]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int ok = 1;
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'P') ok = 0;
        }
        if (ok) {
            if (pref[i][m] == 0) {
                cout << 1 << '\n';
                return;
            }
            if (pref[i][m] == pref[n][m]) {
                cout << 1 << '\n';
                return;
            }
        }
    }
    int sum = 0;
    for (int j = 1; j <= m; ++j) {
        int ok = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i][j] == 'A') ok++;
            else sum++;
        }
        if (ok == n) {
            if (sum == 0) {
                cout << 1 << '\n';
                return;
            }
            if (sum == pref[n][m]) {
                cout << 1 << '\n';
                return;
            }
        }
    }
    if (a[1][1] == 'A' || a[1][m] == 'A' || a[n][1] == 'A' || a[n][m] == 'A') {
        cout << 2 << '\n';
        return;
    }
    //cout << "WA" << '\n';
    int L = n + 1, R = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i][1] == 'P') {
            L = min(L, i), R = max(R, i);
        }
    }
    for (int j = 1; j <= m; ++j) {
        if (col[R][j] - col[L - 1][j] == 0) {
            //cout << L << " " << R << '\n';
            cout << 2 << '\n';
            return;
        }
    }
    L = n + 1, R = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i][m] == 'P') {
            L = min(L, i), R = max(R, i);
        }
    }
    for (int j = 1; j <= m; ++j) {
        if (col[R][j] - col[L - 1][j] == 0) {
            cout << 2 << '\n';
            return;
        }
    }
    L = m + 1, R = -1;
    for (int j = 1; j <= m; ++j) {
        if (a[1][j] == 'P') {
            L = min(L, j), R = max(R, j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (row[i][R] - row[i][L - 1] == 0) {
            cout << 2 << '\n';
            return;
        }
    }
    L = m + 1, R = -1;
    for (int j = 1; j <= m; ++j) {
        if (a[n][j] == 'P') {
            L = min(L, j), R = max(R, j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (row[i][R] - row[i][L - 1] == 0) {
            cout << 2 << '\n';
            return;
        }
    }
    //cout << "WA" << '\n';
    for (int i = 0; i < 61; ++i) mx[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int j = 1;
        while (j <= m) {
            if (a[i][j] == 'P') {
                ++j;
                continue;
            }
            int s = j;
            while (a[i][j] == 'A') ++j;
            mx[s] = max(mx[s], j - 1);
        }
    }
    for (int i = 1; i <= 61; ++i) mx[i] = max(mx[i], mx[i - 1]);
    vector < int > f;
    for (int j = 1; j <= m; ++j) {
        if (a[1][j] == 'P') {
            f.push_back(j);
        }
        else {
            cout << 3 << '\n';
            return;
        }
    }
    for (int pos = 0; pos < (int)f.size() - 1; ++pos) {
        int lef1 = f[0], righ1 = f[pos], lef2 = f[pos + 1], righ2 = f.back();
        if (mx[lef1] >= righ1 && mx[lef2] >= righ2) {
            cout << 3 << '\n';
            return;
        }
    }
    f = {};
    for (int j = 1; j <= m; ++j) {
        if (a[n][j] == 'P') {
            f.push_back(j);
        }
        else {
            cout << 3 << '\n';
            return;
        }
    }

    for (int pos = 0; pos < (int)f.size() - 1; ++pos) {
        int lef1 = f[0], righ1 = f[pos], lef2 = f[pos + 1], righ2 = f.back();
        if (mx[lef1] >= righ1 && mx[lef2] >= righ2) {
            cout << 3 << '\n';
            return;
        }
    }
    for (int i = 0; i <= 61; ++i) mx[i] = 0;
    for (int j = 1; j <= m; ++j) {
        int i = 1;
        while (i <= n) {
            if (a[i][j] == 'P') {
                ++i;
                continue;
            }
            int s = i;
            while (i <= n && a[i][j] == 'A') ++i;
            mx[s] = max(mx[s], i - 1);
        }
    }
    for (int i = 1; i <= 61; ++i) mx[i] = max(mx[i], mx[i - 1]);
    f = {};
    for (int i = 1; i <= n; ++i) {
        if (a[i][1] == 'P') f.push_back(i);
        else {
            cout << 3 << '\n';
            return;
        }
    }
    for (int pos = 0; pos < (int)f.size() - 1; ++pos) {
        int lef1 = f[0], righ1 = f[pos], lef2 = f[pos + 1], righ2 = f.back();
        if (mx[lef1] >= righ1 && mx[lef2] >= righ2) {
            cout << 3 << '\n';
            return;
        }
    }
    f = {};
    for (int i = 1; i <= n; ++i) {
        if (a[i][m] == 'P') f.push_back(i);
        else {
            cout << 3 << '\n';
            return;
        }
    }
    for (int pos = 0; pos < (int)f.size() - 1; ++pos) {
        int lef1 = f[0], righ1 = f[pos], lef2 = f[pos + 1], righ2 = f.back();
        if (mx[lef1] >= righ1 && mx[lef2] >= righ2) {
            cout << 3 << '\n';
            return;
        }
    }
    cout << 4 << '\n';
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}