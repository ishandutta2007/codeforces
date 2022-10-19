#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int add = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            a[i] = 1;
            add++;
        }
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
            if (h[a] > h[b]) {
                p[b] = a;
            } else if (h[a] < h[b]) {
                p[a] = b;
            } else {
                p[b] = a, h[a]++;
            }
        }
    };
    auto count = [&]() {
        DSU d(n);
        vector<int> prv(30, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (a[i] & (1 << j)) {
                    if (prv[j] != -1) {
                        d.unite(prv[j], i);
                    }
                    prv[j] = i;
                }
            }
        }
        int cmp = 0;
        for (int i = 0; i < n; ++i) {
            if (d.pr(i) == i) {
                cmp++;
            }
        }
        if (cmp == 1) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 1) {
                return cmp - 1;
            }
        }
        return cmp;
    };
    int ans = add + count(), i_val = 0, d_val = 0;
    for (int i = 0; i < n; ++i) {
        int mx = 0;
        for (int j = 0; j < 30; ++j) {
            if (a[i] & (1 << j)) {
                mx++;
            } else {
                break;
            }
        }
        for (int d = 1; d < a[i] && d < 30; ++d) {
            int nw = 0;
            for (int j = 0; j < 30; ++j) {
                if ((a[i] - d) & (1 << j)) {
                    nw++;
                } else {
                    break;
                }
            }
            if (nw > mx) {
                mx = nw;
                a[i] -= d;
                int cnt = count();
                if (add + d + cnt < ans) {
                    ans = add + d + cnt;
                    i_val = i;
                    d_val = d;
                }
                a[i] += d;
            }
        }
    }
    cout << ans << '\n';
    a[i_val] -= d_val;
    DSU d(n);
    vector<int> prv(30, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (a[i] & (1 << j)) {
                if (prv[j] != -1) {
                    d.unite(prv[j], i);
                }
                prv[j] = i;
            }
        }
    }
    int cmp = 0;
    for (int i = 0; i < n; ++i) {
        if (d.pr(i) == i) {
            cmp++;
        }
    }
    if (cmp == 1) {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 1) {
            for (int j = 0; j < n; ++j) {
                if (d.pr(j) == j && d.pr(j) != d.pr(i)) {
                    a[j]++;
                }
                cout << a[j] << ' ';
            }
            cout << '\n';
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (d.pr(i) == i) {
            a[i]++;
        }
        cout << a[i] << ' ';
    }
    cout << '\n';
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