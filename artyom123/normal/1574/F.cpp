#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;
const int mod = 998244353;

vector<set<int>> gto, gin, g;
vector<int> ban, usd;

void dfs1(int v, vector<int> &now) {
    now.pb(v);
    usd[v] = 1;
    for (auto &to : g[v]) {
        if (!usd[to]) dfs1(to, now);
    }
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n);
    ban.resize(k);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        a[i].resize(c);
        map<int, int> kek;
        for (auto &l : a[i]) {
            cin >> l; l--;
        }
        for (auto &l : a[i]) {
            kek[l]++;
            if (kek[l] > 1) {
                for (auto &p : a[i]) ban[p] = 1;
                break;
            }
        }
    }
    g.resize(k);
    gin.resize(k);
    gto.resize(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < (int)a[i].size(); j++) {
            gto[a[i][j]].insert(a[i][j + 1]);
            gin[a[i][j + 1]].insert(a[i][j]);
            g[a[i][j]].insert(a[i][j + 1]);
            g[a[i][j + 1]].insert(a[i][j]);
        }
    }
    usd.resize(k);
    vector<vector<int>> comp;
    map<int, int> len;
    for (int v = 0; v < k; v++) {
        if (usd[v]) continue;
        vector<int> now;
        dfs1(v, now);
        bool ok = 1;
        for (auto &c : now) {
            if (ban[c]) ok = 0;
        }
        int cntto0 = 0, cntin0 = 0;
        for (auto &c : now) {
            if ((int)gto[c].size() > 1 || (int)gin[c].size() > 1) ok = 0;
            if (gto[c].empty()) cntto0++;
            if (gin[c].empty()) cntin0++;
        }
        if (ok && cntto0 && cntin0) len[now.size()]++;
    }
    vector<ll> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        for (auto &c : len) {
            if (i + c.fi > m) continue;
            dp[i + c.fi] += c.se * dp[i];
            dp[i + c.fi] %= mod;
        }
    }
    cout << dp[m];
    return 0;
}