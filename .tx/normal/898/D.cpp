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
int o[222222];

void solve(istream& cin, ostream& cout) {
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, 0, n) {
        cin >> a[i];
    }
    if (k == 1) {
        cout << n;
        return;
    }
    if (m == 1) {
        cout << 0;
        return;
    }
    sort(a, a + n);
    int cr = 0;
    int lst = 0;
    int ans = 0;
    fill(o, o + n, true);
    rep(i, 0, n) {
        while (a[i] - a[lst] + 1 > m) {
            if (o[lst]) {
                cr--;
            }
            lst++;
        }
        if (cr + 1 == k) {
            o[i] = false;
            ans++;
        } else {
            cr++;
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