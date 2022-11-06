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

void solve(istream& cin, ostream& cout) {
    int t;
    cin >> t;
    rep(it, 0, t) {
        lint x, y, p, q;
        cin >> x >> y >> p >> q;
        if (p == q) {
            if (x != y) {
                cout << "-1\n";
            } else {
                cout << "0\n";
            }
            continue;
        }
        if (x * q == p * y) {
            cout << "0\n";
            continue;
        }
        if (p == 0) {
            cout << "-1\n";
            continue;
        }
        lint k = max((y - x + q - p - 1) / (q - p), (y + q - 1) / q);
        k = max(k, (x + p - 1) / p);
        k = max(k - 1, 1LL);
        for (;; k++) {
            lint s = k * p - x;
            lint t = k * q - y;
            if (t > 0 && s >= 0 && s <= t) {
                cout << t << "\n";
                break;
            }
        }
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