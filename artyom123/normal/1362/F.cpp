#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

struct edge{
    int ind, a, b, to;
    edge(){}
    edge(int _ind, int _a, int _b, int _to) {
        ind = _ind;
        a = _a;
        b = _b;
        to = _to;
    }
};

vector<vector<edge>> g;
vector<int> cnt;
vector<int> deg;
vector<int> usd;
vector<pair<int, int>> path;

void dfs(int v) {
    while (cnt[v] < (int)g[v].size()) {
        int tmp = cnt[v];
        cnt[v]++;
        if (usd[g[v][cnt[v] - 1].ind]) continue;
        //cout << v << " " << cnt[v] - 1 << " " << usd[g[v][cnt[v - 1]].ind] << endl;
        usd[g[v][tmp].ind] = 1;
        dfs(g[v][tmp].to);
        path.pb(g[v][tmp].a, g[v][tmp].b);
    }
}


int get_last(int x, int k) {
    return (x & ((1 << k) - 1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        int a, b;
        cin >> a >> b;
        for (int k = 20; k >= 0; k--) {
            if (get_last(a, k) == get_last(b, k)) {
                cout << k << "\n" << " " << 1 << " " << 2;
                return 0;
            }
        }
        return 0;
    }
    vector<int> a(2 * n);
    for (auto &c : a) cin >> c;
    for (int k = 20; k >= 0; k--) {
        vector<vector<int>> groups(1 << k);
        vector<int> ind_group(2 * n);
        cnt.clear();
        deg.clear();
        cnt.resize(1 << k);
        deg.resize(1 << k);
        for (int i = 0; i < 2 * n; i++) {
            ind_group[i] = get_last(a[i], k);
            groups[ind_group[i]].pb(i);
        }
        for (int i = 0; i < n; i++) {
            deg[ind_group[2 * i]]++;
            deg[ind_group[2 * i + 1]]++;
        }
        bool can = true;
        for (auto &c : deg) if (c % 2 != 0) can = false;
        if (!can) continue;
        g.clear();
        g.resize(1 << k);
        usd.assign(n, 0);
        for (int i = 0; i < n; i++) {
            int v = ind_group[2 * i], u = ind_group[2 * i + 1];
            //cout << v << " " << u << " " << 2 * i << " " << 2 * i + 1 << endl;
            g[v].pb(i, 2 * i, 2 * i + 1, u);
            g[u].pb(i, 2 * i + 1, 2 * i, v);
        }
        path.clear();
        for (int i = 0; ; i++) {
            if (deg[i] != 0) {
                dfs(i);
                break;
            }
        }
        if ((int)path.size() < n) continue;
        reverse(all(path));
        cout << k << "\n";
        for (auto &c : path) cout << c.fi + 1 << " " << c.se + 1 << " ";
        return 0;
    }
    return 0;
}