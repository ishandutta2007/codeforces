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

bool has(int s, int x) {
    int i = s / 50 % 475;
    rep(ii, 0, 25) {
        i = (i * 96 + 42) % 475;
        if (i + 26 == x) {
            return true;
        }
    }
    return false;
}

void solve(istream& cin, ostream& cout) {
    int p, x, y;
    cin >> p >> x >> y;
    for (int i = 0; x - i * 50 >= y; i++) {
        if (has(x - i * 50, p)) {
            cout << 0;
            return;
        }
    }
    for (int i = 1; ; i++) {
        if (has(x + i * 100, p) || has(x + i * 100 - 50, p)) {
            cout << i;
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