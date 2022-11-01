#include <bits/stdc++.h> 

using namespace std;

const int N = 2e5 + 10;

vector <int> g[N];
int color[N], n, par[N];

void dfs (int u, int p) {
    par[u] = p;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

void bfs (void) {
    queue <int> q;
    q.push(1);
    color[1] = 1;
    while (not q.empty()) {
        int u = q.front(); 
        q.pop();
        int now = 1;
        for (int v : g[u]) {
            if (color[v] != -1) continue;
            while (now == color[u] or now == color[par[u]]) {
                ++now;
            }
            color[v] = now++;
            q.push(v);
        }
    }
}

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(color, -1, sizeof color);
    dfs(1, 1);
    bfs();
    int biggest = 1;
    for (int i = 1; i <= n; ++i) {
        biggest = max(biggest, color[i]);
    }
    printf("%d\n", biggest);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", color[i]);
    } puts("");
    return 0;
}