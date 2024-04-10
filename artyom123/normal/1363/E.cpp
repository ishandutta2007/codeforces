#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const long long INF = 1e18 + 1;

vector<int> a, b, c;
vector<vector<int>> g;
vector<int> cnt0, cnt1;
vector<int> done;

long long ans = 0;

void dfs(int v, int p, long long mn) {
    if (b[v] == 0 && c[v] == 1) cnt0[v]++;
    if (b[v] == 1 && c[v] == 0) cnt1[v]++;
    mn = min(mn, (long long)a[v]);
    for (auto &to : g[v]) {
        if (to == p) continue;
        dfs(to, v, mn);
        cnt0[v] += cnt0[to];
        cnt1[v] += cnt1[to];
    }
    if (cnt0[v] == 0 && cnt1[v] == 0) {
        done[v] = 1;
        return;
    }
    if (a[v] != mn) return;
    if (cnt0[v] == cnt1[v]) {
        done[v] = 1;
        ans += (cnt0[v] + cnt1[v]) * mn;
        cnt0[v] = cnt1[v] = 0;
        return;
    }
    int tmp = min(cnt0[v], cnt1[v]);
    ans += (2 * tmp) * mn;
    cnt0[v] -= tmp;
    cnt1[v] -= tmp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    done.resize(n);
    g.resize(n);
    cnt0.resize(n);
    cnt1.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[v].pb(u);
        g[u].pb(v);
    }
    dfs(0, -1, INF);
    if (!done[0]) cout << -1;
    else cout << ans;
    return 0;
}