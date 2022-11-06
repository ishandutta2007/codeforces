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

bool like(int v, int x) {
    return v <= x && 2 * v >= x;
}

void solve(istream& cin, ostream& cout) {
    int v1, v2, v3, v4;
    cin >> v1 >> v2 >> v3 >> v4;
    rep(x1, v4, 201) {
        rep(x2, v4, x1) {
            rep(x3, v4, x2) {
                if (!like(v1, x1)) {
                    continue;
                }
                if (!like(v2, x2)) {
                    continue;
                }
                if (!like(v3, x3)) {
                    continue;
                }
                if (like(v4, x1) || like(v4, x2) || !like(v4, x3)) {
                    continue;
                }
                cout << x1 << "\n" << x2 << "\n" << x3;
                return;
            }
        }
    }
    cout << -1;
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