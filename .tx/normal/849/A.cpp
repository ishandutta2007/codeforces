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

bool d[111][2];
int a[111];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    if (a[0] % 2 == 0) {
        cout << "No";
        return;
    }
    d[0][0] = true;
    rep(i, 0, n) {
        if (a[i] & 1) {
            if (i % 2 == 0) {
                d[i + 1][1] = true;
            }
            for (int j = i - 1; j > 0; j--) {
                if ((a[j] & 1) && (a[j - 1] & 1) && (i - j) % 2 == 1) {
                    d[i + 1][0] |= d[j][1];
                    d[i + 1][1] |= d[j][0];
                }
            }
        }
    }

    cout << (d[n][1] ? "Yes" : "No");
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