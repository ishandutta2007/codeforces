#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define ld long double
#define pb emplace_back
#define ll long long
#define pii pair<int, int>

const ll INFLL = 1e18;
const int INF = 1e9 + 1;
const ll mod = 998244353;
const int MAXN = 2e5 + 10;

vector<unordered_map<int, int>> a;
vector<int> id;
vector<vector<pair<int, pii>>> g;
vector<ll> dp;
vector<ll> res;

vector<unordered_map<int, int>> fact;
vector<int> inv;

ll my_pow(ll n, ll m) {
    if (m == 0) return 1;
    ll now = my_pow(n, m / 2);
    now = (now * now) % mod;
    if (m % 2 == 1) now = (now * n) % mod;
    return now;
}

void dfs(int v, int p) {
    for (auto &to : g[v]) {
        if (to.fi == p) continue;
        dfs(to.fi, v);
    }
    if ((int)g[v].size() == 1 && p != -1) {
        res[v] = 1;
        dp[v] = 1;
        id[v] = a.size();
        a.pb(unordered_map<int, int>());
        return;
    }
    int best = -1;
    for (auto &to : g[v]) {
        if (to.fi == p) continue;
        int x = to.se.fi, y = to.se.se;
        int need = x / __gcd(x, y);
        for (auto &c : fact[need]) {
            while (a[id[to.fi]][c.fi] < c.se) {
                a[id[to.fi]][c.fi]++;
                dp[to.fi] *= c.fi;
                dp[to.fi] %= mod;
                res[to.fi] *= c.fi;
                res[to.fi] %= mod;
            }
        }
        for (auto &c : fact[y]) {
            a[id[to.fi]][c.fi] += c.se;
            for (int i = 0; i < c.se; i++) {
                res[to.fi] *= c.fi;
                res[to.fi] %= mod;
            }
        }
        for (auto &c : fact[x]) {
            a[id[to.fi]][c.fi] -= c.se;
            for (int i = 0; i < c.se; i++) {
                res[to.fi] *= inv[c.fi];
                res[to.fi] %= mod;
            }
        }
        if (best == -1 || a[id[to.fi]].size() > a[id[best]].size()) best = to.fi;
    }
    res[v] = res[best];
    id[v] = id[best];
    for (auto &to : g[v]) {
        if (to.fi == p) continue;
        if (id[to.fi] == id[v]) continue;
        for (auto &c : a[id[to.fi]]) {
            while (c.se > a[id[v]][c.fi]) {
                a[id[v]][c.fi]++;
                res[v] *= c.fi;
                res[v] %= mod;
            }
        }
    }
    dp[v] = res[v];
    for (auto &to : g[v]) {
        if (to.fi == p) continue;
        ll need = (res[v] * my_pow(res[to.fi], mod - 2)) % mod;
        dp[v] += dp[to.fi] * need;
        dp[v] %= mod;
    }
}

void solve() {
    int n;
    cin >> n;
    g.clear();
    g.resize(n);
    a.clear();
    for (int it = 0; it < n - 1; it++) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        i--; j--;
        g[i].pb(j, mp(y, x));
        g[j].pb(i, mp(x, y));
    }
    dp.clear();
    dp.resize(n);
    res.clear();
    res.resize(n);
    id.clear();
    id.resize(n);
    dfs(0, -1);
    cout << dp[0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact.resize(MAXN);
    inv.resize(MAXN);
    for (int x = 1; x < MAXN; x++) inv[x] = my_pow(x, mod - 2);
    for (int x = 1; x < MAXN; x++) {
        int y = x;
        for (int i = 2; i * i <= y; i++) {
            while (y % i == 0) {
                fact[x][i]++;
                y /= i;
            }
        }
        if (y > 1) fact[x][y]++;
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
1
4
3 2 3 4
1 2 4 3
1 4 2 4
*/