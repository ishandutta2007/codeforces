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
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };

const int M = 998244353;
lint d[5555][5555];
lint p[5555];

void solve(istream& cin, ostream& cout) {
    rep(i, 0, 5555) {
        d[i][0] = 1;
        rep(j, 1, i + 1) {
            d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % M;
        }
    }
    p[0] = 1;
    rep(i, 1, 5555) {
        p[i] = p[i - 1] * i % M;
    }

    int a, b, c;
    cin >> a >> b >> c;

    lint a1 = 0;
    rep(i, 0, min(a, b) + 1) {
        a1 = (a1 + d[b][i] * d[a][i] % M * p[i]) % M;
    }

    lint a2 = 0;
    rep(i, 0, min(a, c) + 1) {
        rep(j, 0, min(b, c) + 1) {
            a2 = (a2 + d[a][i] * d[c][i] % M * p[i] % M * d[b][j] % M * d[c][j] % M * p[j]) % M;
        }
    }

    cout << a1 * a2 % M;
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