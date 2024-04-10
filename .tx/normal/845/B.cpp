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

void solve(istream& cin, ostream& cout) {
    int x;
    cin >> x;
    int ans = 6;
    rep(i, 0, 1e6) {
        int t = i;
        int s1 = 0;
        rep(j, 0, 3) {
            s1 += t % 10;
            t /= 10;
        }
        int s2 = 0;
        rep(j, 0, 3) {
            s2 += t % 10;
            t /= 10;
        }
        if (s1 != s2) {
            continue;
        }
        t = i;
        int y = x;
        int cc = 0;
        rep(j, 0, 6) {
            if (y % 10 != t % 10) {
                cc++;
            }
            y /= 10;
            t /= 10;
        }
        ans = min(ans, cc);
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