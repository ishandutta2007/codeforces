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
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };

void solve(istream& cin, ostream& cout) {
    double k, d, t;
    cin >> k >> d >> t;
    cout << setprecision(11) << fixed;
    if (k >= d) {
        double x = k / d;
        d *= ceil(x);
    }
    double l = 0, r = 1e19;
    rep(iii, 0, 1000) {
        double m = (l + r) / 2;
        double fd = floor(m / d);
        double pd = m - fd * d;
        double x = fd * k + fd * (d - k) * 0.5 + min(k, pd) + max(0, pd - k) * 0.5;
        if (x >= t) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l;
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