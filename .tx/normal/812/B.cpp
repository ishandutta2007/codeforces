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

int l[111];
int r[111];
int d[22][2];

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    m += 2;
    rep(i, 0, n) {
        string s;
        cin >> s;
        rep(j, 0, s.size()) {
            if (s[j] == '1') {
                l[i] = j;
            }
        }
        repr(j, s.size(), 0) {
            if (s[j] == '1') {
                r[i] = s.size() - j - 1;
            }
        }
    }

    d[n - 1][0] = 2 * l[n - 1];
    d[n - 1][1] = m - 1;
    repr(i, n - 1, 0) {
        d[i][0] = min(d[i + 1][0] + 2 * l[i], d[i + 1][1] + m - 1) + 1;
        d[i][1] = min(d[i + 1][1] + 2 * r[i], d[i + 1][0] + m - 1) + 1;
    }
    int ans = l[n - 1];
    rep(i, 0, n - 1) {
        if (l[i] != 0) {
            ans = min(d[i + 1][0] + l[i], d[i + 1][1] + r[i]) + 1;
            break;
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