#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), nxt(n, -1), prv(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> pos;
    map<int, vector<int>> pp;
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = -1;
        pp[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        if (pos[a[i]] != -1) {
            nxt[pos[a[i]]] = i;
            prv[i] = pos[a[i]];
        }
        pos[a[i]] = i;
    }
    vector<int> l(m), r(m);
    vector<vector<int>> qs_l(n);
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        qs_l[l[i]].push_back(i);
    }
    int rr = -1;
    int r2 = -1;
    set<int> brs;
    map<int, int> kek;
    for (int i = 0; i < n; ++i) {
        for (auto q : qs_l[i]) {
            r2 = max(r2, r[q]);
        }
        if (r2 != -1) {
            int p = upper_bound(pp[a[i]].begin(), pp[a[i]].end(), r2) - pp[a[i]].begin() - 1;
            if (p != -1 && pp[a[i]][p] > i) {
                brs.insert(nxt[i]);
                kek[i] = pp[a[i]][p];
                rr = max(rr, prv[pp[a[i]][p]]);
            }
        }
    }
    if (rr == -1) {
        cout << 0 << '\n';
        return;
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, rr - i + 1);
        if (brs.count(i)) {
            break;
        }
        rr = max(rr, kek[i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}