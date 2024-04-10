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

int a[111111];
int mxl[111111];
int mxr[111111];
int mnl[111111];
int mnr[111111];

void solve(istream& cin, ostream& cout) {
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        mxl[i] = a[i];
        mnl[i] = a[i];
        if (i) {
            mxl[i] = max(mxl[i], mxl[i - 1]);
            mnl[i] = min(mnl[i], mnl[i - 1]);
        }
    }

    repr(i, n, 0) {
        mxr[i] = a[i];
        mnr[i] = a[i];
        if (i != n - 1) {
            mxr[i] = max(mxr[i], mxr[i + 1]);
            mnr[i] = min(mnr[i], mnr[i + 1]);
        }
    }

    lint ans = -5e18;

    rep(i, 0, n) {
        lint cur = 1LL * q * a[i];
        if (p < 0) {
            cur += 1LL * p * mnl[i];
        } else {
            cur += 1LL * p * mxl[i];
        }
        if (r < 0) {
            cur += 1LL * r * mnr[i];
        } else {
            cur += 1LL * r * mxr[i];
        }
        ans = max(ans, cur);
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