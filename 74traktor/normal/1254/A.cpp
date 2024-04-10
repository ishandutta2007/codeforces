#include<bits/stdc++.h>

using namespace std;

char a[105][105];
char ans[105][105];

void solve() {
    int r, c, k;
    cin >> r >> c >> k;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) cin >> a[i][j];
    }
    int cnt = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) if (a[i][j] == 'R') cnt++;
    }
    vector < char > g;
    for (int i = 0; i <= 9; ++i) g.push_back(char('0' + i));
    for (int i = 0; i < 26; ++i) g.push_back(char('a' + i)), g.push_back(char('A' + i));
    int i = 1, j = 1, w = 1;
    for (int s = 0; s < k; ++s) {
        int d = cnt / k;
        if (s < cnt % k) d++;
        while (d) {
            ans[i][j] = g[s];
            if (a[i][j] == 'R') d--;
            j += w;
            if (j == c + 1) j = c, i++, w = -1;
            else if (j == 0) j = 1, i++, w = 1;
        }
    }
    while (i <= r) {
        ans[i][j] = g[k - 1];
        j += w;
        if (j == c + 1) j = c, i++, w = -1;
        else if (j == 0) j = 1, i++, w = 1;
    }
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) cout << ans[i][j];
        cout << '\n';
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}