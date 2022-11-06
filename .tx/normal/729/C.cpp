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

pair<int, int> cv[222222];
int g[222222];
int mxv[222222];
int n, k, s, t;

bool can(int v) {
    int cur = 0;
    lint nt = 0;
    rep(i, 0, k) {
        int d = g[i] - cur;
        if (d > v) {
            return false;
        }
        if (d * 2 <= v) {
            nt += d;
            cur = g[i];
            continue;
        }
        int x = 2 * d - v;
        nt += 2 * x + d - x;
        cur = g[i];
    }
    return nt <= t;
}

void solve(istream& cin, ostream& cout) {
    cin >> n >> k >> s >> t;
    rep(i, 0, n) {
        cin >> cv[i].first >> cv[i].second;
    }
    rep(i, 0, k) {
        cin >> g[i];
    }
    g[k++] = s;
    sort(cv, cv + n);
    sort(g, g + k);
    rep(i, 0, n) {
        mxv[i] = cv[i].second;
        if (i) {
            mxv[i] = max(mxv[i], mxv[i - 1]);
        }
    }
    int l = -1, r = n;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        if (can(mxv[m])) {
            r = m;
        } else {
            l = m;
        }
    }
    if (r == n) {
        cout << -1;
    } else {
        cout << cv[r].first;
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
}