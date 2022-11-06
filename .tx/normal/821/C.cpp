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
    int n;
    cin >> n;
    vector<int> b;
    set<int> a;
    int cur = 1;
    int ans = 0;
    rep(i, 0, 2 * n) {
        string s;
        cin >> s;
        if (s == "add") {
            int x;
            cin >> x;
            b.push_back(x);
        } else {
            if (!b.empty() && b.back() == cur) {
                b.pop_back();
            } else if (b.empty() && *a.begin() == cur) {
                a.erase(a.begin());
            } else {
                ans++;
                a.insert(b.begin(), b.end());
                b.clear();
                a.erase(a.begin());
            }
            cur++;
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