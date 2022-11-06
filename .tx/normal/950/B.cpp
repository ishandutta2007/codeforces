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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, m) {
        cin >> b[i];
    }
    int x = 0, y = 0;
    int sx = 0, sy = 0;
    int ans = 0;
    while (x < n && y < m) {
        if (sx < sy) {
            sx += a[x++];
        } else if (sy < sx) {
            sy += b[y++];
        } else {
            ans++;
            sx += a[x++];
            sy += b[y++];
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