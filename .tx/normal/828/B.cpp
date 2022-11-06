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

string a[111];

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    int l = 1e9, r = -1, u = 1e9, d = -1;
    int cb = 0;
    rep(i, 0, n) {
        cin >> a[i];
        rep(j, 0, m) {
            if (a[i][j] == 'B') {
                cb++;
                l = min(l, j);
                r = max(r, j);
                u = min(u, i);
                d = max(d, i);
            }
        }
    }

    if (r == -1) {
        cout << 1;
        return;
    }

    int h = d - u + 1;
    int w = r - l + 1;
    int x = max(h, w);
    if (x > n || x > m) {
        cout << -1;
        return;
    }
    cout << x * x - cb;
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