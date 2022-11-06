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

int ans[2222][33];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    rep(m, 0, n + 1) {
        rep(x, 0, 26) {
            char c = char(x + 'a');
            int r = 0;
            int u = m;
            rep(i, 0, n) {
                if (i && m && s[i - 1] != c) {
                    u++;
                }
                while (r < n && (s[r] == c || u > 0)) {
                    if (s[r] != c) {
                        u--;
                    }
                    r++;
                }
                ans[m][x] = max(ans[m][x], r - i);
            }
        }
    }

    int q;
    cin >> q;
    rep(iq, 0, q) {
        int m;
        char c;
        cin >> m >> c;
        cout << ans[m][c - 'a'] << "\n";
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