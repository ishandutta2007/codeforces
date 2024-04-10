#include <bits/stdc++.h>

using namespace std;

#define sz(a)           int((a).size())
#define all(a)          (a).begin(), (a).end()
#define FOR(i,a,b)      for (int i = 0, _n(b); i < _n; ++i)
#define REP(i,n)        FOR(i, 0, n)

int bit(int x) { return 1 << x; }

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    vector<int> a, b;
    cin >> n >> m;
    REP (i, n) {
        int x, y;
        cin >> x >> y;
        a.push_back(bit(x) | bit(y));
    }
    REP (i, m) {
        int x, y;
        cin >> x >> y;
        b.push_back(bit(x) | bit(y));
    }
    vector<int> p(n, 0), q(m, 0);
    int u = 0;
    REP (i, n) REP (j, m) {
        int z = a[i] & b[j];
        if (z && (z & z - 1) == 0) {
            u |= z;
            p[i] |= z;
            q[j] |= z;
            continue;
        }
    }
    if (u && (u & u - 1) == 0) {
        cout << __builtin_ctz(u) << endl;
        return 0;
    }
    for (int x : p) if (x & (x & x - 1)) {
        cout << -1 << endl;
        return 0;
    }
    for (int x : q) if (x & (x & x - 1)) {
        cout << -1 << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}