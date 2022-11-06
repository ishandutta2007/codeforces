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

int st[11];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    fill(st, st + 11, 2);
    rep(in, 0, n) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "|") {
            rep(i, 0, 10) {
                if (hbit(x, i)) {
                    st[i] = 1;
                }
            }
        } else if (s == "&") {
            rep(i, 0, 10) {
                if (!hbit(x, i)) {
                    st[i] = 0;
                }
            }
        } else {
            rep(i, 0, 10) {
                if (hbit(x, i)) {
                    if (st[i] < 2) {
                        st[i] = 1 - st[i];
                    } else {
                        st[i] = 5 - st[i];
                    }
                }
            }
        }
    }
    int ao = 0;
    int ax = 0;
    int aa = shl(10) - 1;
    rep(i, 0, 10) {
        if (st[i] == 1) {
            ao |= shl(i);
        } else if (st[i] == 0) {
            aa ^= shl(i);
        } else if (st[i] == 3) {
            ax |= shl(i);
        }
    }
    cout << 3 << "\n" << "| " << ao << "\n" << "^ " << ax << "\n& " << aa;
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