#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const int INF = 1e9 + 1;

vector<vector<int>> g;
vector<int> dist;
vector<int> par;

void dfs(int v, int p) {
    par[v] = p;
    for (auto &to : g[v]) {
        if (to == p) continue;
        dist[to] = dist[v] + 1;
        dfs(to, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    int v = -1;
    for (int i = 0; i < n; i++) {
        if ((int)g[i].size() > 1) {
            v = i; break;
        }
    }
    dist.resize(n);
    par.resize(n);
    dfs(v, -1);
    int cnt0 = 0, cnt1 = 0;
    set<int> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((int)g[i].size() == 1 && dist[i] % 2 == 0) cnt0++;
        if ((int)g[i].size() == 1 && dist[i] % 2 == 1) cnt1++;
        if ((int)g[i].size() == 1 && ((int)g[par[i]].size() > 2 || v == par[i])) {
            s.insert(par[i]);
            cnt++;
        }
    }
    if (cnt0 == 0 || cnt1 == 0) cout << 1 << " ";
    else cout << 3 << " ";
    cout << n - 1 - cnt + (int)s.size();
    return 0;
}