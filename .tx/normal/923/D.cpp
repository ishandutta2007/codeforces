#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename T> using vc = std::vector<T>;

void solve(istream& cin, ostream& cout) {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<int> ss(n), st(m);
    vector<int> ls(n), lt(m);
    rep(i, 0, n) {
        if (s[i] != 'A') {
            ss[i] = 1;
        } else {
            ls[i] = 1;
            if (i) {
                ls[i] += ls[i - 1];
            }
        }
        if (i) {
            ss[i] += ss[i - 1];
        }
    }
    rep(i, 0, m) {
        if (t[i] != 'A') {
            st[i] = 1;
        } else {
            lt[i] = 1;
            if (i) {
                lt[i] += lt[i - 1];
            }
        }
        if (i) {
            st[i] += st[i - 1];
        }
    }

    int q;
    cin >> q;
    rep(iq, 0, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a; --b; --c; --d;
        int x1 = ss[b];
        if (a) {
            x1 -= ss[a - 1];
        }
        int x2 = st[d];
        if (c) {
            x2 -= st[c - 1];
        }
        int l1 = min(ls[b], b - a + 1);
        int l2 = min(lt[d], d - c + 1);
        if (x1 > x2) {
            cout << 0;
            continue;
        }
        if (l1 < l2) {
            cout << 0;
            continue;
        }
        if (x1 == x2) {
            if (l1 % 3 != l2 % 3) {
                cout << 0;
                continue;
            }
            cout << 1;
            continue;
        }
        if (x1 == 0 && l1 == l2 && l1 != 0) {
            cout << 0;
            continue;
        }

        if (x2 % 2 != x1 % 2) {
            cout << 0;
            continue;
        }
        cout << 1;
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}