#include <bits/stdc++.h>

using namespace std;
#define int long long
int ans = 0;
vector <vector <int>> a;
vector <int> g, pr, st;
set <pair <int, int>> l;
vector <bool> used;
void dfs(int v, int p, int now) {
    g[v] = now;
    pr[v] = p;
    for (int i : a[v]) {
        if (i != p) dfs(i, v, now + 1);
    }
    if (a[v].size() == 1 && v != 0) {
        l.insert({g[v], v});
    }
}

void flex(int v, int p, int now) {
    if (used[v]) {
        ans += g[v] - now;
    }
    for (int i : a[v]) {
        if (i == p) continue;
        if (used[v]) {
            flex(i, v, now + 1);
        }
        else {
            flex(i, v, now);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    used.resize(n);
    a.resize(n);
    pr.resize(n);
    st.resize(n, -1);
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
        ++st[x - 1];
        ++st[y - 1];
    }
    dfs(0, -1, 0);
    vector <int> kol(n);
    int now = 0;
    while (now < k) {
        ++now;
        pair <int, int> tmp = *l.rbegin();
        l.erase(tmp);
        used[tmp.second] = true;
        --st[pr[tmp.second]];
        kol[pr[tmp.second]] += kol[tmp.second] + 1;
        if (st[pr[tmp.second]] == 0 && pr[tmp.second] != 0) {
            pair <int, int> tm = {g[pr[tmp.second]] - kol[pr[tmp.second]], pr[tmp.second]};
            l.insert(tm);
        }
    }
    flex(0, -1, 0);
    cout << ans;
}