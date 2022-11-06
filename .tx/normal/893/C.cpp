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

int mn[111111];
int c[111111];
vector<int> g[111111];
int cc[111111];

void dfs(int v, int x) {
    mn[x] = min(mn[x], c[v]);
    cc[v] = x;
    for (int i : g[v]) {
        if (cc[i] == -1) {
            dfs(i, x);
        }
    }
}

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> c[i];
    }
    fill(mn, mn + n, int(1e9));
    fill(cc, cc + n, -1);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int x = 0;
    lint ans = 0;
    rep(i, 0, n) {
        if (cc[i] == -1) {
            dfs(i, x);
            ans += mn[x];
            x++;
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