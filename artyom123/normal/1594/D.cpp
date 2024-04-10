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
#define ui unsigned
#define ull unsigned long long
#define ld long double

const long long INFLL = 1e18;
const int INF = 1e9 + 5;
const int mod = 1e9 + 7;

vector<vector<pii>> g;
vector<vector<int>> usd;
vector<vector<int>> col;

void dfs(int v, int beg, bool &ok, int &cnt) {
    usd[v][beg] = 1;
    if (col[v][beg]) cnt++;
    for (auto &to : g[v]) {
        if (!usd[to.fi][beg]) {
            col[to.fi][beg] = (col[v][beg] ^ to.se);
            dfs(to.fi, beg, ok, cnt);
        } else {
            if (col[to.fi][beg] != (col[v][beg] ^ to.se)) ok = 0;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n);
    while (m--) {
        int i, j;
        cin >> i >> j; i--; j--;
        string s;
        cin >> s;
        int c = 0;
        if (s[0] == 'i') c = 1;
        g[i].pb(j, c);
        g[j].pb(i, c);
    }
    usd.assign(n, vector<int>(2, 0));
    col.assign(n, vector<int>(2, 0));
    int ans = 0;
    for (int v = 0; v < n; v++) {
        if (usd[v][0]) continue;
        bool ok0 = 1, ok1 = 1;
        int cnt0 = 0, cnt1 = 0;
        col[v][0] = 0;
        col[v][1] = 1;
        dfs(v, 0, ok0, cnt0);
        dfs(v, 1, ok1, cnt1);
        if (!ok0 && !ok1) {
            cout << -1 << "\n";
            return;
        }
        if (!ok0) ans += cnt1;
        else if (!ok1) ans += cnt0;
        else ans += max(cnt0, cnt1);
    }
    cout << ans << "\n";
    return;
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
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}