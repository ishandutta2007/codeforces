#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n, string(3, '0'));
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i][j];
        }
    }
    vector<int> pr1(n + 1);
    for (int i = 0; i < n; ++i) {
        pr1[i + 1] = pr1[i] + count(a[i].begin(), a[i].end(), '1');
    }
    struct DSU {
        int n;
        vector<int> p, h;

        DSU(int _n) {
            n = _n;
            h.assign(n, 1);
            p.resize(n);
            iota(p.begin(), p.end(), 0);
        }
        int pr(int v) {
            if (p[v] == v) {
                return v;
            }
            return p[v] = pr(p[v]);
        }
        void unite(int a, int b) {
            a = pr(a), b = pr(b);
            if (a == b) {
                return;
            }
            if (h[a] > h[b]) {
                p[b] = a;
            } else if (h[a] < h[b]) {
                p[a] = b;
            } else {
                p[b] = a, h[a]++;
            }
        }
    };
    DSU d(n * 3);
    vector<int> pr2(n + 1);
    for (int i = 0; i < n; ++i) {
        pr2[i + 1] = pr2[i];
        for (int j = 0; j < 2; ++j) {
            if (a[i][j] == '1' && a[i][j + 1] == '1') {
                d.unite(i * 3 + j, i * 3 + j + 1);
                pr2[i + 1]++;
            }
        }
    }
    vector<int> pr3(n + 1);
    for (int i = 1; i < n; ++i) {
        pr3[i + 1] = pr3[i];
        for (int j = 0; j < 3; ++j) {
            if (a[i][j] == '1' && a[i - 1][j] == '1' && d.pr(i * 3 + j) != d.pr((i - 1) * 3 + j)) {
                d.unite(i * 3 + j, (i - 1) * 3 + j);
                pr3[i + 1]++;
            }
        }
    }
    vector<int> nxt(n, n);
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != "101") {
            nxt[i] = i;
        } else if (i + 1 != n) {
            nxt[i] = nxt[i + 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (nxt[l] == l) {
            cout << pr1[r] - pr1[l] - (pr2[r] - pr2[l]) - (pr3[r] - pr3[l + 1]) << '\n';
        } else if (nxt[l] >= r) {
            cout << 2 << '\n';
        } else {
            int ans = pr1[r] - pr1[nxt[l]] - (pr2[r] - pr2[nxt[l]]) - (pr3[r] - pr3[nxt[l] + 1]);
            if (a[nxt[l]] == "000" || a[nxt[l]] == "010") {
                ans += 2;
            } else if (a[nxt[l]] != "111") {
                ans += 1;
            }
            cout << ans << '\n';
        }
    }
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