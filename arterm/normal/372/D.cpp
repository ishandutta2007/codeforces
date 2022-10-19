#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cstdlib>

using namespace std;

#define A 20
#define M 100100
#define B 10000000

int p[A][M];
int n, k, tin[M], tout[M], tim = 0, d[M];
vector<int> g[M];
bool u[M];

void read() {
    cin >> n >> k;
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(int v) {
    u[v] = true;
    tin[v] = tim++;
    for (int & to : g[v])
        if (!u[to]) {
            p[0][to] = v;
            d[to] = d[v] + 1;
            dfs(to);
        }
    tout[v] = tim++;
}

bool isAncestor(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

void lcaPrecalc() {
    for (int i = 1; i < A; ++i)
        for (int j = 1; j <= n; ++j)
            p[i][j] = p[i - 1][p[i - 1][j]];
}

int lca(int x, int y) {
    if (isAncestor(x, y))
        return x;
    for (int i = A - 1; i >= 0; --i)
        if (!isAncestor(p[i][x], y))
            x = p[i][x];
    return p[0][x];
}

int distance(int x, int y) {
    return d[x] + d[y] - 2 * d[lca(x, y)];
}

set<pair<int, int>> s;
int sum = 0;

void add(int v) {
    pair<int, int> pl(tin[v], v);
    pair<int, int> pr(tin[v] + B, v);
    if (!s.empty()) {
        int l = (--s.lower_bound(pr)) -> second;
        int r = (s.lower_bound(pl)) -> second;
        sum -= distance(l, r);
        sum += distance(l, v);
        sum += distance(v, r);
    }
    s.insert(pl);
    s.insert(pr);
}

void del(int v) {
    pair<int, int> pl(tin[v], v);
    pair<int, int> pr(tin[v] + B, v);
    s.erase(pl);
    s.erase(pr);
    if (!s.empty()) {
        int l = (--s.lower_bound(pr)) -> second;
        int r = (s.lower_bound(pl)) -> second;
        sum += distance(l, r);
        sum -= distance(l, v);
        sum -= distance(v, r);
    }
}

int getTreeSize() {
    return sum / 2 + 1;
}

void clear() {
    sum = 0;
    s.clear();
}

bool possible(int s) {
    clear();
    for (int i = 1; i <= s; ++i)
        add(i);
    for (int i = s; i <= n; ++i) {
        if (getTreeSize() <= k)
            return true;
        if (s + 1 <= n) {
            del(i - s + 1);
            add(i + 1);
        }
    }
    return false;
}

void bin() {
    int l = 1, r = n, m;
    while (l < r) {
        m = (l + r) / 2;
        if (possible(m + 1))
            l = m + 1;
        else
            r = m;
    }
    cout << l << "\n";
}

 
int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout); 
#endif
    ios_base::sync_with_stdio(0);

    read();
    p[0][1] = 1;
    d[1] = 0;
    dfs(1);
    lcaPrecalc();

    bin();

    return 0;
}