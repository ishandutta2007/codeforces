//#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 300200

int n, m, q, p[M], d[M], r[M], md, mdist;
std::vector<int> g[M];

void ini() {
    for (int i = 0; i < M; ++i) {
        p[i] = i;
        r[i] = 1;
    }
}

int get(int x) {
    return p[x] = p[x] == x ? x : get(p[x]);
}

void uni(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    if (r[x] < r[y])
        swap(x, y);
    p[y] = x;
    r[x]++;
    d[x] = max(max(d[x], d[y]), (d[x] + 1) / 2 + (d[y] + 1) / 2 + 1);
}

void read() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0, x, y; i < m; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        uni(x, y);
    }
}

void dfs(int v, int pred, int dist) {
    if (dist > mdist) {
        mdist = dist;
        md = v;
    }
    for (int & to : g[v])
        if (to != pred)
            dfs(to, v, dist + 1);
}

void pre() {
    for (int i = 1; i <= n; ++i)
        if (p[i] == i) {
            mdist = -1;
            dfs(i, -1, 0);
            mdist = -1;
            dfs(md, -1, 0);
            d[i] = mdist;
        }
}

void kill() {
    for (int i = 0, t, x, y; i < q; ++i) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &x);
            printf("%d\n", d[get(x)]);
        }
        if (t == 2) {
            scanf("%d%d", &x, &y);
            uni(x, y);
        }
    }
}




int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    //ios_base::sync_with_stdio(0);
#endif

    ini();
    read();
    pre();
    kill();


    return 0;
}