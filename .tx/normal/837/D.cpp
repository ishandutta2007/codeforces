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

int d[2][222][5555];
int c5[222];
int c2[222];

void solve(istream& cin, ostream& cout) {
    int n, k;
    cin >> n >> k;
    rep(i, 0, n) {
        lint x;
        cin >> x;
        while (x % 5 == 0) {
            x /= 5;
            c5[i]++;
        }
        while (x % 2 == 0) {
            x /= 2;
            c2[i]++;
        }
    }

    memset(d, -1, sizeof(int) * 2 * 222 * 5555);
    d[1][0][0] = 0;
    d[0][0][0] = 0;

    rep(id, 0, n) {
        int cr = id & 1;
        int pr = cr ^ 1;
        rep(i, 1, n + 1) {
            rep(w5, 0, 5555) {
                d[cr][i][w5] = d[pr][i][w5];
                if (w5 >= c5[id] && d[pr][i - 1][w5 - c5[id]] != -1) {
                    d[cr][i][w5] = max(d[cr][i][w5], d[pr][i - 1][w5 - c5[id]] + c2[id]);
                }
            }
        }
    }

    int ans = 0;
    rep(i5, 0, 5555) {
        int x = min(i5, d[(n - 1) & 1][k][i5]);
        ans = max(ans, x);
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