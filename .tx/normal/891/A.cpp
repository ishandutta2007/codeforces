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

int a[2222];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    int c1 = 0;
    int g = -1;
    rep(i, 0, n) {
        cin >> a[i];
        if (a[i] == 1) {
            c1++;
        }
        if (i == 0) {
            g = a[i];
        } else {
            g = __gcd(g, a[i]);
        }
    }
    if (g != 1) {
        cout << -1;
        return;
    }
    if (c1 != 0) {
        cout << n - c1;
        return;
    }

    int mn = n;
    rep(i, 0, n) {
        int g = a[i];
        rep(j, i + 1, n) {
            g = __gcd(g, a[j]);
            if (g == 1) {
                mn = min(mn, j - i + 1);
                break;
            }
        }
    }

    cout << n + mn - 2;
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