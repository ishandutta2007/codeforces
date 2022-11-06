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
    int h1, a1, c1, h2, a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector<string> ans;
    while (true) {
        if (h2 > a1 && h1 <= a2) {
            ans.push_back("HEAL");
            h1 += c1;
        } else {
            ans.push_back("STRIKE");
            h2 -= a1;
        }
        if (h2 <= 0) {
            break;
        }
        h1 -= a2;
    }
    cout << ans.size() << "\n";
    for (string& s: ans) {
        cout << s << "\n";
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