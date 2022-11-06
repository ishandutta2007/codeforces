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
    int n, a, b;
    cin >> n >> a >> b;
    int b1 = 0;
    int ans = 0;
    rep(in, 0, n) {
        int t;
        cin >> t;
        if (t == 2) {
            if (b == 0) {
                ans += 2;
            } else {
                b--;
            };
        } else {
            if (a) {
                a--;
            } else if (b) {
                b--;
                b1++;
            } else if (b1) {
                b1--;
            } else {
                ans++;
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