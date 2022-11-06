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
    int n, a, b;
    cin >> n >> a >> b;
    int ca = -1, cb = -1;
    rep(i, 0, n / a + 1) {
        if ((n - i * a) % b == 0) {
            ca = i;
            cb = (n - i * a) / b;
            break;
        }
    }
    if (ca == -1 ) {
        cout << -1;
        return;
    }

    int st = 1;
    rep(ia, 0, ca) {
        rep(i, 1, a) {
            cout << st + i << " ";
        }
        cout << st << " ";
        st += a;
    }
    rep(ib, 0, cb) {
        rep(i, 1, b) {
            cout << st + i << " ";
        }
        cout << st << " ";
        st += b;
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