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
    int n, i, l, r;
    cin >> n >> i >> l >> r;
    if (l == 1 && r == n) {
        cout << 0;
        return;
    }
    if (i <= l) {
        int ans = 0;
        if (l != 1) {
            ans += l - i + 1;
        }
        if (r != n) {
            ans += r - l + 1;
        }
        cout << ans;
        return;
    }
    if (i >= r) {
        int ans = 0;
        if (r != n) {
            ans += i - r + 1;
        }
        if (l != 1) {
            ans += r - l + 1;
        }
        cout << ans;
        return;
    }

    if (l == 1) {
        cout << r - i + 1;
        return;
    }

    if (r == n) {
        cout << i - l + 1;
        return;
    }

    cout << min(i - l, r - i) + r - l + 2;
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