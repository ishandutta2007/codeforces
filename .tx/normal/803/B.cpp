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

int a[222222];
int l[222222];
int r[222222];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    int x = -1;
    rep(i, 0, n) {
        if (a[i] == 0) {
            x = i;
        }
        l[i] = x;
    }
    x = -1;
    repr(i, n, 0) {
        if (a[i] == 0) {
            x = i;
        }
        r[i] = x;
    }

    rep(i, 0, n) {
        int ans = 1e9;
        if (l[i] != -1) {
            ans = min(ans, i - l[i]);
        }
        if (r[i] != -1) {
            ans = min(ans, r[i] - i);
        }
        cout << ans << " ";
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