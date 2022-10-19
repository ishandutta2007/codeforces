#include <bits/stdc++.h>

//#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
using namespace std;

void solve() {
    vector<int> n(4);
    for (int i = 0; i < 4; ++i) {
        cin >> n[i];
    }
    vector<vector<int>> a(4);
    for (int i = 0; i < 4; ++i) {
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; ++j) {
            cin >> a[i][j];
        }
    }
    multiset<int> dp;
    vector<vector<int>> dp1 = a;
    for (int i = 0; i < n[0]; ++i) {
        dp.insert(a[0][i]);
    }
    for (int i = 1; i < 4; ++i) {
        int cnt;
        cin >> cnt;
        vector<vector<int>> g(n[i]);
        while (cnt--) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[y].pb(x);
        }
        for (int j = 0; j < n[i]; ++j) {
            for (auto kek: g[j]) {
                if (dp1[i - 1][kek] != -1) {
                    dp.erase(dp.find(dp1[i - 1][kek]));
                }
            }
            if (dp.size() == 0) {
                dp1[i][j] = -1;
            } else {
                dp1[i][j] = *dp.begin() + a[i][j];
            }
            for (auto kek: g[j]) {
                if (dp1[i - 1][kek] != -1) {
                    dp.insert(dp1[i - 1][kek]);
                }
            }
        }
        dp.clear();
        for (int j = 0; j < n[i]; ++j) {
            if (dp1[i][j] != -1) {
                dp.insert(dp1[i][j]);
            }
        }
    }
    if (dp.size() == 0) {
        cout << -1 << '\n';
    } else {
        cout << *dp.begin() << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q = 1;
    //cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}