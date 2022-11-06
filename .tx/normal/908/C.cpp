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
    int n, r;
    cin >> n >> r;
    vector<pair<int, double>> ans;
    rep(i, 0, n) {
        double cr = r;
        int x;
        cin >> x;
        for (auto& t : ans) {
            int ox = t.first;
            double oy = t.second;
            if (abs(x - ox) <= 2 * r) {
                int d = abs(x - ox);
                double y = sqrt(2.0 * r * 2 * r - 1.0 * d * d) + oy;
                cr = max(y, cr);
            }
        }
        ans.push_back({x, cr});
    }
    cout << setprecision(11) << fixed;
    for (auto& t : ans) {
        cout << t.second << " ";
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