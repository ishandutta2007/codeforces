#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 1
using lint = long long;

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    vector<pair<int, int>> a, b;
    a.push_back({1e9, -1});
    b.push_back({-1e9, -1});
    lint ans = 0;
    lint cs = 0;
    rep(i, 0, n) {
        int x;
        cin >> x;
        while (!a.empty() && x > a.back().first) {
            cs += 1LL * (x - a.back().first) * (a.back().second - a[a.size() - 2].second);
            a.pop_back();
        }
        a.push_back({x, i});
        while (!b.empty() && x < b.back().first) {
            cs += 1LL * (b.back().first - x) * (b.back().second - b[b.size() - 2].second);
            b.pop_back();
        }
        b.push_back({x, i});
        ans += cs;
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
    srand(23234793);
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
}//luivjn