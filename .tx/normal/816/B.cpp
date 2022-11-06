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

void solve(istream& cin, ostream& cout) {
    int n, k, q;
    cin >> n >> k >> q;
    rep(i, 0, n) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    int c = 0;
    rep(i, 1, 222222) {
        c += a[i];
        if (c >= k) {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
        a[i] += a[i - 1];
    }

    rep(iq, 0, q) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << "\n";
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