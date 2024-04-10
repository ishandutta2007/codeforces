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

int a[111][111];

void solve(istream& cin, ostream& cout) {
    int n, k;
    cin >> n >> k;
    int c = (k + 1) / 2 - 1;
    rep(in, 0, n) {
        int m;
        cin >> m;
        int md = 1e9;
        int mi = -1;
        int mj = -1;
        rep(i, 0, k) {
            int ct = 0;
            int cd = 0;
            rep(j, 0, m) {
                cd += abs(i - c) + abs(j - c);
                ct += a[i][j];
            }
            if (ct == 0 && cd < md) {
                md = cd;
                mi = i;
                mj = 0;
            }
            rep(j, m, k) {
                cd += abs(i - c) + abs(j - c);
                ct += a[i][j];
                cd -= abs(i - c) + abs(j - m - c);
                ct -= a[i][j - m];
                if (ct == 0 && cd < md) {
                    md = cd;
                    mi = i;
                    mj = j - m + 1;
                }
            }
        }
        if (mi == -1) {
            cout << "-1\n";
        } else {
            cout << mi + 1 << " " << mj + 1 << " " << mj + m << "\n";
            rep(i, 0, m) {
                a[mi][mj + i] = 1;
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
}//gatfcz