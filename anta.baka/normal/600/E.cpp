#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100000;

int n;
int c[N];
vector<int> g[N];
map<int,int> hoc1[N];
map<int,ll> hoc2[N];
ll ans[N];
int link[N];

inline int getSz(int v) {
    return hoc1[link[v]].size();
}

inline void add(int w, int col, int cnt) {
    if(hoc1[w].count(col) == 0) {
        hoc1[w][col] = cnt;
        hoc2[w][cnt] += col;
    } else {
        int old = hoc1[w][col];
        ll _ = (hoc2[w][old] -= col);
        if(!_)
            hoc2[w].erase(old);
        cnt = (hoc1[w][col] += cnt);
        hoc2[w][cnt] += col;
    }
}

void solve(int v, int prev = -1) {
    if(v != 0 && g[v].size() == 1) {
        link[v] = v;
        add(v,c[v],1);
        ans[v] = c[v];
        return;
    }
    int m = g[v].size();
    int bigKid = 0;
    for(int i = 0; i < m; i++)
        if(g[v][i] != prev) {
            solve(g[v][i], v);
            if(getSz(g[v][bigKid]) < getSz(g[v][i]))
                bigKid = i;
        }
    link[v] = link[g[v][bigKid]];
    for(int i = 0; i < m; i++)
        if(i != bigKid && g[v][i] != prev) {
            int to = g[v][i];
            for(auto it = hoc1[link[to]].begin(); it != hoc1[link[to]].end(); it++)
                add(link[v],it->first,it->second);
        }
    add(link[v],c[v],1);
    ans[v] = hoc2[link[v]].rbegin()->second;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    if(n == 1)
        return cout << c[0], 0;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve(0);
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}