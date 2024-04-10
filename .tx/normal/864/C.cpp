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

#define fail cout << -1; return

void solve(istream& cin, ostream& cout) {
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    int c = b;
    int ans = 0;
    rep(ir, 0, k) {
        if (ir % 2 == 0) {
            if (c < f) {
                fail;
            }
            c -= f;
            int d = a - f;
            if (c < d || (ir + 1 < k && c < 2 * d)) {
                ans++;
                c = b;
            }
            if (c < d) {
                fail;
            }
            c -= d;
        } else {
            int d = a - f;
            if (c < d) {
                fail;
            }
            c -= d;
            if (c < f || (ir + 1 < k && c < 2 * f)) {
                ans++;
                c = b;
            }
            if (c < f) {
                fail;
            }
            c -= f;
        }
    }
    cout << ans;
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