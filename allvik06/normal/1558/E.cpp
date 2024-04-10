#include <iostream>
#include <vector>

using namespace std;
#define int long long
const int INF = 1e9 + 1;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(n);
    for (int i = 1; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) cin >> b[i];
    vector <vector <int>> g(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int l = 0, r = INF;

    auto check = [&](int x) {
        int kek = 0;
        vector <int> added(n);
        added[0] = 1;
        kek = 1;
        while (kek < n) {
            int ok = 0;
            vector <int> st, pr(n, -1), d(n);
            for (int i = 0; i < n; ++i) {
                if (a[i] >= x || added[i]) continue;
                int cnt = 0;
                for (int j : g[i]) {
                    cnt += added[j];
                    if (added[j]) {
                        pr[i] = j;
                        d[i] = x + b[i];
                        st.push_back(i);
                    }
                }
                if (cnt > 1) {
                    x += b[i];
                    ok = 1;
                    kek++;
                    added[i] = 1;
                    break;
                }
            }
            if (ok == 1) continue;
            while (!st.empty()) {
                int v = st.back();
                st.pop_back();
                for (int i : g[v]) {
                    if (i == pr[v]) continue;
                    if (added[i]) {
                        int cur = v;
                        while (pr[cur] != -1) {
                            x += b[cur];
                            added[cur] = 1;
                            cur = pr[cur];
                            kek++;
                        }
                        ok = 1;
                        break;
                    }
                    if (d[i] == 0) {
                        if (a[i] < d[v]) {
                            d[i] = d[v] + b[i];
                            pr[i] = v;
                            st.push_back(i);
                        }
                    } else {
                        if (d[i] <= d[v]) {
                            vector <int> used(n);
                            int cur = i;
                            while (pr[cur] != -1) {
                                x += b[cur] * !used[cur];
                                kek += !used[cur];
                                added[cur] = 1;
                                used[cur] = 1;
                                cur = pr[cur];
                            }
                            cur = v;
                            while (pr[cur] != -1) {
                                x += b[cur] * !used[cur];
                                kek += !used[cur];
                                added[cur] = 1;
                                used[cur] = 1;
                                cur = pr[cur];
                            }
                            ok = 1;
                            break;
                        }
                    }
                }
                if (ok == 1) break;
            }
            if (ok == 1) continue;
            break;
        }
        return kek == n;
    };

    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}