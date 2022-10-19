#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 200010;

int n, m, u, v, t;
int a[MAXN], disc[MAXN], fin[MAXN], d[MAXN];
vector <int> E[MAXN];

int f[2 * MAXN];

inline void update(int x, int val) {
    for (; x < 2 * MAXN; x += x & -x)
        f[x] += val;
}

inline int get(int x) {
    int ret = 0;
    for (; x; x -= x & -x) 
        ret += f[x];
    return ret;
}

void dfs(int node, int depth) {
    disc[node] = ++t;
    d[node] = depth;
    for (int i = 0; i < E[node].size(); i++) 
        if (!disc[E[node][i]]) 
            dfs(E[node][i], depth + 1);
    fin[node] = ++t;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 1);
    while (m--) {
        scanf("%d%d", &t, &u);
        if (t == 1) {
            scanf("%d", &v);
            update(disc[u], d[u] & 1 ? -v : v);
            update(fin[u], d[u] & 1 ? v : -v);
        }
        else printf("%d\n", d[u] & 1 ? a[u] - get(disc[u]) : a[u] + get(disc[u]));
    }
    return 0;
}