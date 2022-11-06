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

int a[111];
int b[111];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    n *= 2;
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 1e9;
    rep(f, 0, n) {
        rep(s, f + 1, n) {
            int x = 0;
            rep(i, 0, n) {
                if (i == f || i == s) {
                    continue;
                }
                b[x++] = a[i];
            }
            int cur = 0;
            for (int i = 0; i + 1 < x; i += 2) {
                cur += b[i + 1] - b[i];
            }
            if (cur == -1) {
                cur++;
                cur -= 1;
            }
            ans = min(ans, cur);
        }
    }
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