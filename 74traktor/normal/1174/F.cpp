#include <bits/stdc++.h>

using namespace std;

vector < int > g[200005];
int h[200005];
int sz[200005];
int h_x;
vector < int > hld;

void yes(int v){
    cout << '!' << " " << v << endl;
    exit(0);
}

int ask(int v, char t){
    cout << t << " " << v << endl;
    int x;
    cin >> x;
    return x;
}

void dfs(int v, int p){
    sz[v] = 1;
    for (auto u : g[v]){
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
        sz[v] += sz[u];
    }
}

void hld_build(int v, int p){
    hld.push_back(v);
    int go = -1;
    for (auto u : g[v]){
        if (u == p) continue;
        if (go == -1 || (sz[u] > sz[go])) go = u;
    }
    if (go != -1) hld_build(go, v);
}

void dfs1(int v, int p){
    hld = {};
    hld_build(v, p);
    int ans = ask(hld.back(), 'd');
    if (ans == 0) yes(hld.back());
    int h_down = h[hld.back()];
    int h_y = (h_down + h_x - ans) / 2;
    int to = hld[h_y - h[hld[0]]];
    if (h_down - h_y == ans) yes(to);
    dfs1(ask(to, 's'), to);
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    h_x = ask(1, 'd');
    if (h_x == 0) yes(1);
    dfs1(1, 0);
    return 0;
}