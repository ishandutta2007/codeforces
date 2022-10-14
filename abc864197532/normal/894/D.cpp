#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define test(x) cout << #x << ' ' << x << endl
#define printv(x) { \
    for (auto a : x) cout << a << ' '; \
    cout << endl; \
}
#define pii pair<int, int>
#define pll pair<lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int N = 1 << 20, abc = 864197532;

vector <int> adj[N];
vector <int> dis[N];
vector <lli> pre_sum[N];
int w[N];

void dfs(int v) {
    dis[v].pb(0);
    vector <vector <int>> tmp;
    for (int u : adj[v]) {
        dfs(u);
        tmp.pb({});
        for (int i : dis[u]) {
            if (i + w[u] <= 10000000) tmp.back().pb(i + w[u]);
        }
    }
    if (tmp.size() == 1) {
        for (int i : tmp[0]) {
            dis[v].pb(i);
        }
    } else if (tmp.size() > 1) {
        int i, j;
        for (i = 0, j = 0; i < tmp[0].size() && j < tmp[1].size();) {
            if (tmp[0][i] < tmp[1][j]) dis[v].pb(tmp[0][i++]);
            else dis[v].pb(tmp[1][j++]);
        }
        while (i < tmp[0].size()) dis[v].pb(tmp[0][i++]);
        while (j < tmp[1].size()) dis[v].pb(tmp[1][j++]);
    }
    pre_sum[v].pb(0);
    for (int i = 0; i < dis[v].size(); ++i) {
        pre_sum[v].pb(pre_sum[v].back() + dis[v][i]);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) cin >> w[i];
    for (int i = 1; i < n; ++i) {
        int j = (i + 1) / 2 - 1;
        adj[j].eb(i);
    }
    auto calc = [&](int v, lli val) {
        int p = lower_bound(all(dis[v]), val) - dis[v].begin();
        return 1ll * p * val - pre_sum[v][p];
    };
    dfs(0);
    while (q--) {
        int v;
        lli h;
        cin >> v >> h, --v;
        lli ans = calc(v, h);
        while (v) {
            h -= w[v];
            int u = (v + 1) / 2 - 1;
            ans += calc(u, h) - calc(v, h - w[v]);
            v = u;
        }
        cout << ans << '\n';
    }
}