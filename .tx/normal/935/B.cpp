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
    int n;
    cin >> n;
    int ans = 0;
    string s;
    cin >> s;
    int cx = 0;
    int cy = 0;
    int sd;
    rep(i, 0, n) {
        if (s[i] == 'U') {
            cx++;
        } else {
            cy++;
        }
        if (i == 0) {
            sd = cx - cy;
            continue;
        }
        if (cx - cy == 0) {
            continue;
        }
        if ((sd < 0) != ((cx - cy) < 0)) {
            ans++;
        }
        sd = cx - cy;
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