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
template <typename T> using vc = std::vector<T>;

void solve(istream& cin, ostream& cout) {
    lint n, l;
    cin >> n >> l;
    vc<lint> c(33);
    rep(i, 0, n) {
        cin >> c[i];
        if (i) {
            c[i] = min(c[i], 2 * c[i - 1]);
        }
    }
    rep(i, n, 33) {
        c[i] = 2 * c[i - 1];
    }
    lint ans = lint(3e18);
    lint ex = 0;
    repr(i, 32, 0) {
        if (hbit(l, i)) {
            ans = min(ans, ex + c[i + 1]);
            ex += c[i];
        } else {
            ans = min(ans, ex + c[i]);
        }
    }
    ans = min(ans, ex);
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