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
    int q;
    cin >> q;
    rep(iq, 0, q) {
        int n;
        cin >> n;
        if (n % 4 == 0) {
            cout << n / 4;
        } else if (n % 4 == 1) {
            if (n < 9) {
                cout << -1;
            } else {
                cout << 1 + (n - 9) / 4;
            }
        } else if (n % 4 == 2) {
            if (n < 6) {
                cout << -1;
            } else {
                cout << 1 + (n - 6) / 4;
            }
        } else {
            if (n < 15) {
                cout << -1;
            } else {
                cout << 2 + (n - 15) / 4;
            }
        }
        cout << "\n";
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