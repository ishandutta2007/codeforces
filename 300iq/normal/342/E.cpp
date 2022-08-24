#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
const int K = 18;
const int inf = 1e9;
vector <int> g[N];
int sz[N];
int dad[N];
int h[N];
int res[N];
int d[N][K];
bool u[N];

int cur_centr;
void dfs(int v, int size, int pr) {
    sz[v] = 1;
    bool good = 1;
    for (auto to : g[v]) {
        if (to != pr && !u[to]) {
            dfs(to, size, v);
            sz[v] += sz[to];
            good &= (sz[to] <= size / 2);
        }
    }
    good &= (size - sz[v] <= size / 2);
    if (good) {
        cur_centr = v;
    }
}

void calc_dist(int v, int pr, int cnt) {
    d[v][h[cur_centr]] = cnt;
    for (auto to : g[v]) {
        if (to != pr && !u[to]) {
            calc_dist(to, v, cnt + 1);
        }
    }
}


void build(int v, int pr) {
    cur_centr = -1;
    dfs(v, 0, v);
    dfs(v, sz[v], v);
    u[cur_centr] = 1;
    h[cur_centr] = h[pr] + 1;
    dad[cur_centr] = pr;
    calc_dist(cur_centr, cur_centr, 0);
    int c = cur_centr;
    for (auto to : g[c]) {
        if (!u[to]) {
            build(to, c);
        }
    }
}

int lca(int a, int b) {
    while (h[a] > h[b]) a = dad[a];
    while (h[b] > h[a]) b = dad[b];
    while (a != b) a = dad[a], b = dad[b];
    return a;
}

int dist(int a, int b) {
    int c = lca(a, b);
    return d[a][h[c]] + d[b][h[c]];
}

void print(int v) {
    int cur = v;
    while (cur != 0) {
        res[cur] = min(res[cur], dist(v, cur));
        cur = dad[cur];
    }
}

int get(int v) {
    int cur = v;
    int ret = inf;
    while (cur != 0) {
        ret = min(ret, dist(v, cur) + res[cur]);
        cur = dad[cur];
    }
    return ret;
}



int main() {
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    //cin >> n >> m;
    for (int i = 1; i <= n; i++) res[i] = inf;
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        //cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    build(1, 0);
    print(1);
    for (int i = 0; i < m; i++) {
        int t, v;
        scanf("%d%d", &t, &v);
        //cin >> t >> v;
        if (t == 1) {
            print(v);
        } else {
            printf("%d\n", get(v));
            //cout << get(v) << '\n';
        }
    }
}