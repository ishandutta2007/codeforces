#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define max3(a, b, c) max(max(a, b), c)

const int MAXN = 300005;

int N, M, Q;
int parent[MAXN];
int dist[MAXN];
int node[MAXN];
int path[MAXN];
vector <int> v[MAXN], roots;
bool bio[MAXN];
int tmp[MAXN];
int val[MAXN];

int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (rand() & 1) parent[x] = y;
    else parent[y] = x;
}

void solve(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    int dx = dist[fx];
    int dy = dist[fy];
    x = node[fx];
    y = node[fy];
    int mem = max(dx, dy);
    if (dx == dy) mem++;
    if (dx < dy) 
        swap(x, y);
    join(x, y);
    int t = find(x);
    node[t] = x;
    dist[t] = mem;
    path[t] = max3(path[fx], path[fy], dx + dy + 1);
}

int dfs(int x, int p, int d) {
    bio[x] = true;
    int m1 = 0, m2 = 0;
    for (int i = 0; i < v[x].size(); i++) 
        if (v[x][i] != p) {
            int curr = dfs(v[x][i], x, d + 1);
            if (curr >= m1) { m2 = m1; m1 = curr; }
            else if (curr > m2) m2 = curr;
        }
    for (int i = 0; i < v[x].size(); i++)
        if (v[x][i] != p) {
            if (tmp[v[x][i]] == m1) val[v[x][i]] = m2 - 2 * d;
            else val[v[x][i]] = m1 - 2 * d;
        }
    return tmp[x] = max(m1, d);
}

int mini, maks, idx;

void traverse(int x, int p, int d, int m) {
    int t = max(m + d, tmp[x] - d); 
    for (int i = 0; i < v[x].size(); i++)
        if (v[x][i] != p) traverse(v[x][i], x, d + 1, max(m, val[v[x][i]]));
    if (t < mini) { mini = t; idx = x; }
    maks = max(maks, t);
}

void init() {
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 1; i <= N; i++) 
        parent[i] = i;
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        join(a, b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) 
        if (!bio[i]) {
            dfs(i, 0, 0);
            roots.push_back(i);
        }
    for (int i = 0; i < roots.size(); i++) {
        mini = MAXN; idx = maks = 0;
        traverse(roots[i], 0, 0, 0);
        int f = find(roots[i]);
        node[f] = idx;
        dist[f] = mini;
        path[f] = maks;
    }
}

void solve() {
    while (Q--) {
        int t, a, b;
        scanf("%d%d", &t, &a);
        if (t == 1) {
            printf("%d\n", path[find(a)]);
            continue;
        }
        scanf("%d", &b);
        solve(a, b);
    }
}

int main() {
    init();
    solve();
    return 0;
}