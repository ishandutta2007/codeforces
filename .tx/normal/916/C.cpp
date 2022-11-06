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

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    int w = n - 1;
    while (true) {
        bool prime = w != 1;
        for (int i = 2; i * i <= w; i++) {
            if (w % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            break;
        }
        w++;
    }

    cout << w << " " << w << "\n";
    rep(i, 1, n - 1) {
        cout << i << " " << i + 1 << " " << 1 << "\n";
    }
    cout << n - 1 << " " << n << " " << w - (n - 2) << "\n";
    m -= n - 1;
    rep(i, 0, n) {
        rep(j, i + 2, n) {
            if (m == 0) {
                return;
            }
            --m;
            cout << i + 1 << " " << j + 1 << " " << 1000000000 << "\n";
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