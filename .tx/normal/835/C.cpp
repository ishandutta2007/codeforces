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

int s[11][111][111];
vector<int> a[111][111];

void solve(istream& cin, ostream& cout) {
    int n, q, c;
    cin >> n >> q >> c;
    rep(i, 0, n) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y].push_back(z);
    }
    rep(it, 0, c + 1) {
        for (int i = 1; i < 111; i++) {
            for (int j = 1; j < 111; j++) {
                for (int x : a[i][j]) {
                    s[it][i][j] += (x + it) % (c + 1);
                }
                s[it][i][j] += s[it][i - 1][j] + s[it][i][j - 1] - s[it][i - 1][j - 1];
            }
        }
    }

    rep(iq, 0, q) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= (c + 1);
        int ans = s[t][x2][y2] - s[t][x2][y1 - 1] - s[t][x1 - 1][y2] + s[t][x1 - 1][y1 - 1];
        cout << ans << "\n";
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
}//