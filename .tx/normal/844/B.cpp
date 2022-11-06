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

int c1[55];
int c0[55];
int r1[55];
int r0[55];

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) {
            int x;
            cin >> x;
            if (x == 1) {
                r1[i]++;
                c1[j]++;
            } else {
                r0[i]++;
                c0[j]++;
            }
        }
    }

    lint ans = 0;
    rep(i, 0, n) {
        ans += (1LL << r1[i]) - 1;
        ans += (1LL << r0[i]) - 1;
    }
    rep (i, 0, m) {
        ans += (1LL << c1[i]) - 1;
        ans += (1LL << c0[i]) - 1;
    }
    ans -= n * m;
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