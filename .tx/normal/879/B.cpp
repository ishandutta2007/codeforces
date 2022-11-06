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

int a[555];

void solve(istream& cin, ostream& cout) {
    int n;
    lint k;
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a[i];
    }
    int mx = *max_element(a, a + n);
    int c = 0;
    int p = 0;
    rep(i, 0, n) {
        if (a[i] == mx) {
            cout << mx;
            return;
        }
        if (a[p] > a[i]) {
            c++;
        } else {
            c = i == 0 ? 0 : 1;
            p = i;
        }
        if (c == k) {
            cout << a[p];
            return;
        }
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