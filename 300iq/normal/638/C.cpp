#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;

bool used[MAXN];
int c[MAXN];
int father[MAXN];
vector <pair <int, int> > color[MAXN];
vector <int> g[MAXN];
map <pair <int, int>, int> e;
int res;

void dfs(int v, int pr, int num) {
    father[v] = pr;
    used[v] = 1;
    int i = 0;
    if (v != 1) {
        if (c[pr] == 0) c[pr] = INT_MAX;
        if (num + 1 < c[pr])
            i = num + 1;
        else
            i = num + 2;
    }
    if (v != 1) c[v] = i;
    if (v != 1) color[i].push_back({pr, v});
    res = max(res, i);
    int cnt = 0;
    for (int i = 0; i < (int) g[v].size(); i++) {
        if (!used[g[v][i]]) {
            dfs(g[v][i], v, cnt);
            cnt++;
        }
    }
}


int main() {
    int n, u, v;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        e[{u, v}] = e[{v, u}] = i + 1;
    }
    dfs(1, 0, 0);
    printf("%d\n", res);
    for (int i = 1; i <= res; i++) {
        printf("%d ", (int) color[i].size());
        for (int j = 0; j < (int) color[i].size(); j++)
            printf("%d ", e[color[i][j]]);
        puts("");
    }
}