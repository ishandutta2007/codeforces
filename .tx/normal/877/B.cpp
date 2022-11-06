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

int a[5555];

void solve(istream& cin, ostream& cout) {
    string s;
    cin >> s;
    s = "a" + s + "a";
    int n = s.size();
    rep(i, 0, n) {
        a[i + 1] = s[i] == 'a' ? 1 : 0;
        a[i + 1] += a[i];
    }
    if (a[n] == 0) {
        cout << n;
        return;
    }
    int ans = n - a[n];
    rep(i, 0, n) {
        if (s[i] == 'b') {
            continue;
        }
        ans = max(ans, i - a[i] + 1);
        ans = max(ans, n - i - (a[n] - a[i + 1]));
        rep(j, i + 1, n) {
            if (s[j] == 'b') {
                continue;
            }
            ans = max(ans, a[i + 1] + a[n] - a[j] + (j - i - 1 - (a[j] - a[i + 1])));
        }
    }
    cout << ans - 2;
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