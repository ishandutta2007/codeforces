#include <bits/stdc++.h>

using namespace std;

//#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
map<vector<int>, int> mp;
const int maxn = 2e5 + 5;
vector<int> g2[maxn];
int sz[maxn], pr[maxn], tin[maxn], tout[maxn];
int t = 0;

void dfs(int v, int pr2) {
    pr[v] = pr2;
    t++;
    tin[v] = t;
    sz[v] = 1;
    for (auto u: g2[v]) {
        if (u != pr2) {
            dfs(u, v);
            sz[v] += sz[u];
        }
    }
    t++;
    tout[v] = t;
}

int f[30];

bool solve1(vector<int> v, int nmb) {
    if (v.size() <= 3) {
        return 1;
    }
    if (mp[v]) {
        return mp[v] - 1;
    }
    t = 0;
    dfs(v[0], v[0]);
    vector<int> tin2, tout2;
    for (auto i: v) {
        tin2.pb(tin[i]);
        tout2.pb(tout[i]);
    }
    vector<pair<int, pii>> int1;
    int p = 0;
    for (auto i: v) {
        if (sz[i] == f[nmb - 1] || sz[i] == f[nmb - 2]) {
            int1.pb({i, {p, pr[i]}});
        }
        p++;
    }
    for (auto [i, p2]: int1) {
        int p = p2.f, pr = p2.s;
        vector<int> v1;
        for (int kek = 0; kek < v.size(); ++kek) {
            if (tin2[p] <= tin2[kek] && tout2[kek] <= tout2[p]) {
                v1.pb(v[kek]);
            }
        }
        vector<int> kek;
        for (auto j: g2[i]) {
            if (j != pr) {
                kek.pb(j);
            }
        }
        g2[i] = kek;
        int val1 = nmb - 1;
        if (v1.size() == f[nmb - 2]) {
            val1--;
        }
        int ans = solve1(v1, val1);
        g2[i].pb(pr);
        if (ans == 0) {
            p++;
            continue;
        }
        kek = {};
        for (auto j: g2[pr]) {
            if (j != i) {
                kek.pb(j);
            }
        }
        g2[pr] = kek;
        v1 = {};
        for (int k = 0; k < v.size(); ++k) {
            if (!(tin2[p] <= tin2[k] && tout2[k] <= tout2[p])) {
                v1.pb(v[k]);
            }
        }
        val1 = nmb * 2 - 3 - val1;
        ans = solve1(v1, val1);
        g2[pr].pb(i);
        if (ans) {
            mp[v] = 2;
            return 1;
        }
    }
    mp[v] = 1;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    f[0] = f[1] = 1;
    for (int i = 2; i < 30; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g2[a].pb(b);
        g2[b].pb(a);
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.pb(i);
    }
    for (int i = 0; i < 30; ++i) {
        if (n == f[i]) {
            if (solve1(v, i)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}