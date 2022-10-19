#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), used(m, vector<int>(n)), ans(n, vector<int>(m));
    vector<pair<int, int>> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            b.pb({a[i][j], i});
        }
        sort(all(a[i]));
    }
    sort(all(b));
    int pos = 0;
    for (auto [val, i]: b) {
        while (1) {
            if (used[pos][i]) {
                pos++;
                if (pos == m) {
                    pos = 0;
                }
            } else {
                ans[i][pos] = val;
                used[pos][i] = 1;
                pos++;
                if (pos == m) {
                    pos = 0;
                }
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}