#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5, l = 20;

int centr[l][maxn], dist[l][maxn], val[l][maxn], pr_min[l][maxn], min_pr[l][maxn];

vector<int> g[maxn];

vector<pair<int, int>> kek[maxn];
vector<int> aaa[maxn];

bool c[maxn];

int h[maxn];

int sz[maxn];

void count_sz(int v, int pr) {
    sz[v] = 1;
    for (auto u : g[v]) {
        if (u != pr && !c[u]) {
            count_sz(u, v);
            sz[v] += sz[u];
        }
    }
}

int find_centr(int v, int pr, int ssz) {
    for (auto u : g[v]) {
        if (u != pr && !c[u] && sz[u] * 2 > ssz) {
            return find_centr(u, v, ssz);
        }
    }
    return v;
}

void col(int v, int pr, int i, int vl) {
    centr[i][v] = vl;
    for (auto u : g[v]) {
        if (u != pr && !c[u]) {
            col(u, v, i, vl);
        }
    }
}

void build(int n) {
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < n; ++j) {
            centr[i][j] = -1;
            dist[i][j] = val[i][j] = -1;
            pr_min[i][j] = min_pr[i][j] = 1;
            sz[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (c[j] || centr[i][j] != -1) {
                continue;
            }
            count_sz(j, j);
            int ccc = find_centr(j, j, sz[j]);
            c[ccc] = true;
            col(ccc, ccc, i, ccc);
            queue<int> q;
            q.push(ccc);
            pr_min[i][ccc] = dist[i][ccc] = val[i][ccc] = min_pr[i][ccc] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto u : g[v]) {
                    if (h[u] > h[v] && centr[i][u] == ccc) {
                        dist[i][u] = dist[i][v] + 1;
                        min_pr[i][u] = min(0, min_pr[i][v] + 1);
                        q.push(u);
                    } else if (h[u] == h[v] && centr[i][u] == ccc && min_pr[i][u] == 1) {
                        dist[i][u] = dist[i][v] - 1;
                        min_pr[i][u] = min_pr[i][v] - 1;
                        q.push(u);
                    }
                }
            }
            q.push(ccc);
            vector<int> vvv;
            while (!q.empty()) {
                int v = q.front();
                vvv.push_back(v);
                q.pop();
                for (auto u : g[v]) {
                    if (h[u] == h[v] && centr[i][u] == ccc && pr_min[i][u] == 1) {
                        val[i][u] = val[i][v] - 1;
                        pr_min[i][u] = min(pr_min[i][v], val[i][u]);
                        q.push(u);
                    } else if (h[u] < h[v] && centr[i][u] == ccc && pr_min[i][u] == 1) {
                        val[i][u] = val[i][v] + 1;
                        pr_min[i][u] = pr_min[i][v];
                        q.push(u);
                    }
                }
            }
            for (auto v : vvv) {
                bool ch = false;
                for (auto u : g[v]) {
                    if (h[u] == h[v]) {
                        ch = true;
                        break;
                    }
                }
                if (ch) {
                    kek[ccc].emplace_back(-pr_min[i][v], h[v]);
                    // cout << ccc << ' ' << v << ' ' << -pr_min[i][v] << ' ' << h[v] << '\n';
                }
            }
            sort(kek[ccc].begin(), kek[ccc].end());
            aaa[ccc] = {n};
            for (auto v : kek[ccc]) {
                aaa[ccc].push_back(min(aaa[ccc].back(), v.second));
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        h[i] = -1;
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        int kkk;
        cin >> kkk;
        if (kkk) {
            h[i] = 0;
            q.push(i);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (h[u] == -1) {
                h[u] = h[v] + 1;
                q.push(u);
            }
        }
    }
    build(n);
    for (int i = 0; i < n; ++i) {
        int ans = h[i];
        for (int ll = 0; ll < l; ++ll) {
            if (dist[ll][i] == -1 || min_pr[ll][i] < 0) {
                continue;
            }
            int pos = lower_bound(kek[centr[ll][i]].begin(), kek[centr[ll][i]].end(), make_pair(dist[ll][i] + 1, 0)) - kek[centr[ll][i]].begin();
            ans = max(ans, h[i] * 2 - aaa[centr[ll][i]][pos]);
        }
        cout << ans << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}