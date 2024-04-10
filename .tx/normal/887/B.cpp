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

bool hv[3][11];
int p[3];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, 6) {
            int x;
            cin >> x;
            hv[i][x] = true;
        }
    }

    for (int x = 1; ; x++) {
        rep(i, 0, n) {
            p[i] = i;
        }

        bool ok = false;

        do {
            int y = x;
            int t = 0;
            bool f = true;
            while (y) {
                if (!hv[p[t]][y % 10]) {
                    f = false;
                    break;
                }
                y /= 10;
                t++;
            }
            if (f) {
                ok = true;
                break;
            }
        } while (next_permutation(p, p + n));

        if (!ok) {
            cout << x - 1;
            return;
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