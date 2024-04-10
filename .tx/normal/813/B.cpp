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
    lint x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<lint> xs;
    vector<lint> ys;
    lint cx = 1;
    xs.push_back(cx);
    while (1.0 * cx * x <= r + 100 && cx * x <= r) {
        cx *= x;
        xs.push_back(cx);
    }

    lint cy = 1;
    ys.push_back(cy);
    while (1.0 * cy * y <= r + 100 && cy * y <= r) {
        cy *= y;
        ys.push_back(cy);
    }

    vector<lint> as;
    for (lint i : xs) {
        for (lint j : ys) {
            if (i + j >= l && i + j <= r) {
                as.push_back(i + j);
            }
        }
    }

    sort(as.begin(), as.end());
    lint fs = l;
    lint ans = 0;
    as.push_back(r + 1);
    for (lint i : as) {
        ans = max(ans, i - fs);
        fs = i + 1;
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
}//wbdkps