#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 500005;
const int MOD = 1000000007;

int u[N], v[N], c[N];
int n, m, k;
vector<ii> edges[N];

struct DSU {
    int N;
    int n;
    vector<int> p;
    stack<int> changes;

    DSU(int _n) {
        N = _n;
        n = _n;
        p.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }

    int root(int x) {
        changes.push(x);
        return (p[x] == x) ? x : (p[x] = root(p[x]));
    }

    void merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return;
        p[x] = y;
        changes.push(x);
        n--;
    }

    bool inTheSameSet(int x, int y) {
        return (root(x) == root(y));
    }

    void rollback() {
        n = N;
        while (!changes.empty()) {
            int foo = changes.top();
            changes.pop();
            p[foo] = foo;
        }
    }
};

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return res;
}

// int inv(int x) {
//     return power(x, MOD - 2);
// }

// int fac[N], ifac[N];

// void init_combi() {
//     fac[0] = 1;
//     ifac[0] = 1;
//     for (int i = 1; i < N; i++) {
//         fac[i] = 1LL * fac[i - 1] * i % MOD;
//         ifac[i] = inv(fac[i]); 
//     }
// }

// int C(int n, int k) {
//     return 1LL * ifac[k] * ifac[n - k] % MOD * fac[n] % MOD;
// }

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m >> k;
    set<int> s;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
        s.insert(c[u[i]] ^ c[v[i]]);
    }
    int cur = 0;
    for (auto e : s) mp[e] = ++cur;
    for (int i = 1; i <= m; i++) {
        int foo = (c[u[i]] ^ c[v[i]]);
        edges[mp[foo]].pb({u[i], v[i]});
    }
    DSU dsu = DSU(n);
    int ans = (power(2, k) - cur) * power(2, n) % MOD;
    for (int i = 1; i <= cur; i++) {
        for (auto e : edges[i]) {
            dsu.merge(e.x, e.y);
        }
        ans = (ans + power(2, dsu.n)) % MOD;
        dsu.rollback();
    }
    cout << (ans + MOD) % MOD;
    return 0;
}