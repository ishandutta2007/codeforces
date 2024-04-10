#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()

const int N = 1e5 + 10;

vector<int> e[N];
vector<int> used[N];
vector<int> g[N];
int sz[N];
int color[N];
int blocked[N];

int dfs_sz(int v, int p = -1) {
    sz[v] = 1;
    for (auto u: g[v])
        if (u != p)
            sz[v] += dfs_sz(u, v);
    return sz[v];
}

void dfsD(int v, int c = 0) {
    for (auto u: g[v]) {
        if (!blocked[u] && sz[u] * 2 > sz[v]) {
            int tot = sz[v];
            sz[v] -= sz[u];
            sz[u] = tot;
            v = u;
            dfsD(u, c);
            return;
        }
    }
    color[v] = c;
    blocked[v] = 1;
    for (auto u: g[v]) 
        if (!blocked[u])
            dfsD(u, c + 1);
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    for (int i = 0; i < n; i++) {
        e[i].pb((i + 1) % n);
        e[(i + 1) % n].pb(i);
    }

    for (int i = 0; i < n; i++) {
        sort(all(e[i]));
        used[i].resize(e[i].size());
    }
    
    vector<vector<int>> face;
    for (int st = 0; st < n; st++) {
        for (int j = 0; j < (int)e[st].size(); j++) {
            if (used[st][j]) 
                continue;
            int u = e[st][j];
            if ((u + 1) % n == st) 
               continue; 
            int id = j;
            int v = st;
            vector<int> reg;
            while (!used[v][id]) {
                reg.pb(v);
                used[v][id] = 1;
                int newV = e[v][id];
                int newId = lower_bound(all(e[newV]), v) - e[newV].begin();
                newId = (newId - 1 + e[newV].size()) % e[newV].size();
                v = newV;
                id = newId;
            }
            sort(all(reg));
            reverse(all(reg));
            face.pb(reg);
        }      
    }
    sort(all(face));
    map<pair<int,int>,int> q;
    for (int j = 0; j < (int)face.size(); j++) {
        auto& reg = face[j];
        for (int i = 0; i < (int)reg.size(); i++) {
            int v = reg[i];
            int u = reg[(i + 1) % reg.size()];
            if (v > u) swap(v, u);
            if (q.count(mp(v, u)) == 0) {
                q[mp(v, u)] = j;
            }
            else {
                int other = q[mp(v, u)];
                g[j].pb(other);
                g[other].pb(j);
            }
        }
    }

    dfs_sz(0);
    dfsD(0);
    for (int i = 0; i <= m; i++)
        printf("%d ", color[i] + 1);    
    puts("");
    return 0;
}