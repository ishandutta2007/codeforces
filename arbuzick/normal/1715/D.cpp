#include <bits/stdc++.h>

using namespace std;

const int lg = 30, inf = (1 << lg) - 1;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> d(n);
    vector<vector<pair<int, int>>> qs(n);
    for (int i = 0; i < q; ++i) {
        int a, b, x;
        cin >> a >> b >> x;
        a--, b--;
        qs[min(a, b)].emplace_back(max(a, b), x);
        d[a] |= (inf ^ x);
        d[b] |= (inf ^ x);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        for (auto [j, x] : qs[i]) {
            a[i] |= (x & d[j]);
            if (j == i) {
                a[i] |= x;
            }
        }
        for (auto [j, x] : qs[i]) {
            a[j] |= (x & (x ^ a[i]));
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}