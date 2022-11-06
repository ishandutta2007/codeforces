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
    int n;
    cin >> n;
    rep(in, 0, n) {
        int a, b;
        cin >> a >> b;
        lint x = 1LL * a * b;
        lint t = floor(pow(x, 1.0 / 3.0)) - 2;
        t = max(t, 1LL);
        while (1LL * (t + 1) * (t + 1) * (t + 1) <= x) {
            t++;
        }
        if (t * t * t != x || a % t || b % t) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
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
}//yjwjqk