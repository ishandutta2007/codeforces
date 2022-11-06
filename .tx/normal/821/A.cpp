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

int a[55][55];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> a[i][j];
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            if (a[i][j] == 1) {
                continue;
            }
            bool ok = false;
            rep(x, 0, n) {
                rep(y, 0, n) {
                    if (a[i][j] == a[i][x] + a[y][j]) {
                        ok = true;
                    }
                }
            }
            if (!ok) {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
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