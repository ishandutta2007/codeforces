#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 1
using lint = long long;

int a[111111];
int d[111111];

void solve(istream& cin, ostream& cout) {
    int n, k;
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a[i];
        --a[i];
        if (a[i] == -1) {
            d[i] = 1 + min(k, i) + min(k, n - i - 1);
        } else {
            int x1 = min(n - 1, i + k);
            int x2 = min(n - 1, a[i] + k);
            int x3 = 0;
            if (i - a[i] - 1 > k) {
                x3 = min(k, i - a[i] - 1 - k);
            }
            d[i] = d[a[i]] + min(x1 - i + 1, x1 - x2) + x3;
        }
        cout << d[i] << " ";
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
    srand(236);
    for (int ti = 0; ti < 1000; ti++) {
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