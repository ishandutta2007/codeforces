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

int a[111111];
lint c[111111];

void solve(istream& cin, ostream& cout) {
    int n, s;
    cin >> n >> s;
    rep(i, 0, n) {
        cin >> a[i];
    }

    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        rep(i, 0, n) {
            c[i] = a[i] + 1LL * (i + 1) * m;
        }
        nth_element(c, c + m, c + n);
        lint cs = 0;
        rep(i, 0, m) {
            cs += c[i];
        }
        if (cs <= s) {
            l = m;
        } else {
            r = m;
        }
    }

    int m = l;
    rep(i, 0, n) {
        c[i] = a[i] + 1LL * (i + 1) * m;
    }
    nth_element(c, c + m, c + n);
    lint cs = 0;
    rep(i, 0, m) {
        cs += c[i];
    }

    cout << m << " " << cs;


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