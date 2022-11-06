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

lint d[44][44];

void solve(istream& cin, ostream& cout) {
    int n, h;
    cin >> n >> h;
    d[1][0] = 1;
    d[1][1] = 1;
    rep(i, 2, n + 1) {
        repr(j, n + 1, 1) {
            d[i][j] = 2 * d[i - 1][j - 1];
            rep(k, 1, i - 1) {
                d[i][j] += d[k][j - 1] * d[i - 1 - k][1];
                d[i][j] += (d[k][1] - d[k][j - 1]) * d[i - 1 - k][j - 1];
            }
        }
        d[i][0] = d[i][1];
    }

    cout << d[n][h];
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
}//eghiee