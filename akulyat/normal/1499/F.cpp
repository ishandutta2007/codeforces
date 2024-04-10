#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
vector<int> d, q, INV;
vector<vector<int>> e, kids;
vector<vector<int>> dp, pref;
vector<int> all;
bool viv = false;

void DFS(int v, int c = 0) {
    d[v] = c;
    for (auto u : e[v]) {
        if (d[u] == -1) {
            kids[v].push_back(u);
            DFS(u);
        }
    }
    q.push_back(v);
}

void prepare() {
    dp.resize(n, vector<int>(n, 0));
    pref.resize(n, vector<int>(n + 1, 0));
    all.resize(n);
}

ll gp(int v, int p) {
    p = max(p, -1);
    p = min(p, n - 1);
    return (all[v] + pref[v][p + 1]) % mod;
}

void work(int v) {
    dp[v][0] = 1;
    for (auto u : kids[v]) {
        ll will = (ll)dp[v][0] * all[u];
        will %= mod;
        dp[v][0] = will;
    }
    ll left[kids[v].size() + 1];
    ll right[kids[v].size() + 1];
    for (int l = 1; l <= k; l++) {
        int lim_a = min(l - 1, k - l) - 1;
        int lim_b = min(l, k - l) - 1;
        left[0] = right[0] = 1;
        for (int i = 0; i < kids[v].size(); i++)
            left[i + 1]  = (left[i]  * gp(kids[v][i],                      lim_a)) % mod;
        for (int i = 0; i < kids[v].size(); i++)
            right[i + 1] = (right[i] * gp(kids[v][kids[v].size() - 1 - i], lim_b)) % mod;

        int le = 0;
        int ri = kids[v].size();
        for (auto u : kids[v]) {
            ri--;
            ll res = dp[u][l - 1];
            res *= left[le]; res %= mod;
            res *= right[ri]; res %= mod;
            dp[v][l] += res;
            dp[v][l] %= mod;
            le++;
        }
    }

    for (auto i : dp[v])
        all[v] += i, all[v] %= mod;
    for (int i = 0; i < n; i++)
        pref[v][i + 1] = (pref[v][i] + dp[v][i]) % mod;
}

void solve() {
    cin >> n >> k;
    e.resize(n);
    kids.resize(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }  
    d.resize(n, -1);
    DFS(0);

    prepare();
    for (auto v : q)
        work(v);

    ll ans = 0;
    for (auto i : dp[0]) {
        ans += i;
        ans %= mod;
    }
    cout << ans << '\n';
}

int main() {
    // viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; 
    // cin >> t;
    while (t--)
        solve();

    return 0;
}