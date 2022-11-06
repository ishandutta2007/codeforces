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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    int s, f;
    cin >> s >> f;
    int l = f - s;
    int c = 0;
    rep(i, 0, l - 1) {
        c += a[i];
    }
    int mx = 0;
    int aa = -1;
    int ans = 1e9;
    int cs = s;
    rep(i, 0, n) {
        c += a[(i + l - 1) % n];
        if (c > mx) {
            mx = c;
            ans = 1e9;
        }
        if (c == mx) {
            ans = min(ans, cs);
        }
        c -= a[i];
        cs--;
        if (cs == 0) {
            cs = n;
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