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

bool h7(int x) {
    while (x) {
        if (x % 10 == 7) {
            return true;
        }
        x /= 10;
    }
    return false;
}

void solve(istream& cin, ostream& cout) {
    int x, hh, mm;
    cin >> x >> hh >> mm;
    int m = mm + hh * 60;
    for (int i = 0; ; i++) {
        if (h7(m % 60) || h7(m / 60)) {
            cout << i;
            return;
        }
        m -= x;
        if (m < 0) {
            m += 24 * 60;
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