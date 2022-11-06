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

int x[111];
int y[111];

void solve(istream& cin, ostream& cout) {
    int n, a, b;
    cin >> n >> a >> b;
    rep(i, 0, n) {
        cin >> x[i];
        cin >> y[i];
    }

    int ans = 0;

    rep(iab, 0, 2) {
        swap(a, b);
        rep(iall, 0, 2) {
            rep(i, 0, n) {
                swap(x[i], y[i]);
            }
            rep(i, 0, n) {
                if (x[i] > a || y[i] > b) {
                    continue;
                }
                rep(j, i + 1, n) {
                    rep(ij, 0, 2) {
                        swap(x[j], y[j]);
                        if (x[j] <= a && y[j] <= b) {
                            if (y[i] + y[j] <= b || x[i] + x[j] <= a) {
                                ans = max(ans, x[i] * y[i] + x[j] * y[j]);
                            }
                        }
                    }
                }
            }
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