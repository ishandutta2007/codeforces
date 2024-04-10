#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 42, sigma = 22, inf = 1e9;

vector<pair<int, int>> g[maxn];

int in[maxn], out[maxn], rin[maxn], sz[maxn], h[maxn], t;
int ans[maxn], mask[maxn];

int xr, pl;
int msk_h[1 << sigma];

void print(int x, int y) {
    for(int c = 0; c < sigma; c++) {
        if((x >> c) & 1) {
            cout << char('a' + c) << ' ';
        }
    }
    cout << y << endl;
}

void dfs(int v = 0, bool need = 0) {
    msk_h[0] = 0;
    if(g[v].empty()) {
        if(!need) {
            msk_h[0] = -inf;
        }
        return;
    }
    
    for(int i = 1; i < g[v].size(); i++) {
        dfs(g[v][i].first, 0);
        ans[v] = max(ans[v], ans[g[v][i].first]);
    }
    
    dfs(g[v][0].first, 1);
    ans[v] = max(ans[v], ans[g[v][0].first]);
    xr ^= 1 << g[v][0].second;
    pl += 1;
    msk_h[xr] = max(msk_h[xr], -pl);
    
    ans[v] = max(ans[v], msk_h[xr] + pl);
    for(int c = 0; c < sigma; c++) {
        ans[v] = max(ans[v], msk_h[xr ^ (1 << c)] + pl);
    }
    
    for(int i = 1; i < g[v].size(); i++) {
        int u = g[v][i].first;
        for(int i = in[u]; i < out[u]; i++) {
            int path = mask[rin[i]] ^ mask[v];
            ans[v] = max(ans[v], msk_h[path ^ xr] + pl + h[rin[i]] - h[v]);
            for(int c = 0; c < sigma; c++) {
                ans[v] = max(ans[v], msk_h[path ^ xr ^ (1 << c)] + pl + h[rin[i]] - h[v]);
            }
        }
        for(int i = in[u]; i < out[u]; i++) {
            int path = mask[rin[i]] ^ mask[v];
            msk_h[path ^ xr] = max(msk_h[path ^ xr], h[rin[i]] - h[v] - pl);
        }
    }
    if(!need) {
        msk_h[0] = msk_h[xr] = -inf;
        for(int i = in[v]; i < out[v]; i++) {
            int path = mask[rin[i]] ^ mask[v];
            msk_h[path ^ xr] = -inf;
        }
        xr = pl = 0;
    }
}

void dfs_sz(int v = 0) {
    sz[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        dfs_sz(g[v][i].first);
        sz[v] += sz[g[v][i].first];
        if(sz[g[v][i].first] > sz[g[v][0].first]) {
            swap(g[v][i], g[v][0]);
        }
    }
}

void dfs_inout(int v = 0) {
    in[v] = t++;
    rin[in[v]] = v;
    for(auto it: g[v]) {
        h[it.first] = h[v] + 1;
        mask[it.first] = mask[v] ^ (1 << it.second);
        dfs_inout(it.first);
    }
    out[v] = t;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(msk_h, msk_h + (1 << sigma), -inf);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int p;
        char c;
        cin >> p >> c;
        g[p - 1].push_back({i, c - 'a'});
    }
    dfs_sz();
    dfs_inout();
    dfs();
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}