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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = 1e9;
    int x = -1;
    for (int i = 0; i + n <= m; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] != t[i + j]) {
                c++;
            }
        }
        if (c < ans) {
            ans = c;
            x = i;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i + x]) {
            cout << i + 1 << " ";
        }
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