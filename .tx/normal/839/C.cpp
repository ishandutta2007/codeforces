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

double ans = 0;
vector<int> g[111111];

void dfs(int v, int p, double pr, int d) {
    int t = (d == 0 ? g[v].size() : g[v].size() - 1);
    if (t == 0) {
        ans += pr * d;
        return;
    }
    double cp = 1.0 / t;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v, pr * cp, d + 1);
    }
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1, 1, 0);
    cout << fixed << setprecision(11) << ans;
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