#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;
#define bint __int128_t

inline bint gcd(bint a, bint b) {
    for (; b > 0; a %= b, swap(a, b)) {}
    return a;
}

struct SegTree {
    int n;
    vector <bint> t;

    inline SegTree(int n) : n(n) {
        t.resize(4 * n, 1);
    }

    void update(int v, int l, int r, int i, bint x) {
        if (l > i || i > r) return;
        if (l == r) {
            t[v] = x;
            return;
        }
        int m = (l + r) / 2;
        update(2 * v, l, m, i, x);
        update(2 * v + 1, m + 1, r, i, x);
        t[v] = t[2 * v] / gcd(t[2 * v], t[2 * v + 1]) * t[2 * v + 1];
    }

    inline void upd(int i, bint x) {
        update(1, 0, n - 1, i, x);
    }
};

inline void print(bint a) {
    vector <int> all;
    while (a > 0) {
        all.push_back(a % 10);
        a /= 10;
    }
    reverse(all.begin(), all.end());
    for (int i : all) cout << i;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<bint> a(n), b(m);
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            bint now = 0;
            for (char c: s) {
                now = now * 10 + c - '0';
            }
            a[i] = now;
        }
        for (int i = 0; i < m; ++i) {
            cin >> s;
            bint now = 0;
            for (char c: s) {
                now = now * 10 + c - '0';
            }
            b[i] = now;
        }
        vector <SegTree> ta(n, SegTree(m)), tb(m, SegTree(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ta[i].upd(j, gcd(a[i], b[j]));
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                tb[i].upd(j, gcd(b[i], a[j]));
            }
        }
        vector<bool> nowa(n), nowb(m);
        while (true) {
            bool ok = false;
            for (int i = 0; i < n; ++i) {
                if (nowa[i]) continue;
                if (ta[i].t[1] != a[i]) {
                    nowa[i] = true;
                    ok = true;
                    for (int j = 0; j < m; ++j) {
                        tb[j].upd(i, 1);
                    }
                }
            }
            for (int i = 0; i < m; ++i) {
                if (nowb[i]) continue;
                if (tb[i].t[1] != b[i]) {
                    nowb[i] = true;
                    ok = true;
                    for (int j = 0; j < n; ++j) {
                        ta[j].upd(i, 1);
                    }
                }
            }
            if (!ok) break;
        }
        int cnta = 0, cntb = 0;
        for (int i = 0; i < n; ++i) cnta += nowa[i];
        for (int i = 0; i < m; ++i) cntb += nowb[i];
        if (cnta == n || cntb == m) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << n - cnta << " " << m - cntb << "\n";
            for (int i = 0; i < n; ++i) {
                if (!nowa[i]) {
                    print(a[i]);
                    cout << " ";
                }
            }
            cout << "\n";
            for (int i = 0; i < m; ++i) {
                if (!nowb[i]) {
                    print(b[i]);
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
}

/*

 */