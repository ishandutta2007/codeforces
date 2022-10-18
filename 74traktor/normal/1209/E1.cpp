#include <bits/stdc++.h>

using namespace std;

int a[15][105];
vector < int > go;
int n, m, ans = 0;
int where[15];
int imax[15];

void dfs(int v) {
    if (v == (int)go.size()) {
        for (int j = 1; j <= n; ++j) imax[j] = 0;
        for (int i = 0; i < (int)go.size(); ++i) {
            for (int j = 1; j <= n; ++j) {
                int nxt = (j + where[i]);
                if (nxt > n) nxt -= n;
                imax[nxt] = max(imax[nxt], a[j][go[i]]);
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; ++i) sum += imax[i];
        ans = max(ans, sum);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        where[v] = i;
        dfs(v + 1);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    vector < pair < int, int > > T;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            T.push_back({i, j});
        }
    }
    sort(T.begin(), T.end(), [](pair < int, int > c, pair < int, int > d) {
        return a[c.first][c.second] > a[d.first][d.second];
    });
    go = {};
    ans = 0;
    for (int i = 0; i < (int)T.size(); ++i) {
        int ok = 1;
        for (auto key : go) {
            if (key == T[i].second) ok = 0;
        }
        if (ok) go.push_back(T[i].second);
        if ((int)go.size() > 6) break;
    }
    dfs(0);
    cout << ans << '\n';
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