//#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

#define M 500500

bool t[8 * M];

inline void push(int v) {
    if (t[v]) {
        t[2 * v] = t[2 * v + 1] = true;
    }
}

void zero(int v, int l, int r, int pos) {
    push(v);
    t[v] = false;
    if (l + 1 == r) 
        return;
    int m = (l + r) / 2;
    if (pos < m)
        zero(2 * v, l, m, pos);
    else
        zero(2 * v + 1, m, r, pos);
}

void one(int v, int l, int r, int le, int re) {
    push(v);
    if (l == le && r == re) {
        t[v] = true;
        return;
    }
    int m = (l + r) / 2;

    if (le < m) 
        one(2 * v, l, m, le, min(re, m));

    if (m < re)
        one(2 * v + 1, m, r, max(m, le), re);

    t[v] = t[2 * v] && t[2 * v + 1];
}

bool get(int v, int l, int r, int le, int re) {
    push(v);
    if (l == le && r == re) {
        return t[v];
    }
    int m = (l + r) / 2;
    bool ans = true;
    if (le < m)
        ans &= get(2 * v, l, m, le, min(m, re));
    if (m < re)
        ans &= get(2 * v + 1, m, r, max(m, le), re);
    return ans;
}

int n;
int l[M], r[M], time = 0, p[M];
vector<int> g[M];
bool u[M];

void read() {
    scanf("%d", &n);
    for (int i = 1, x, y; i < n; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(int v) {
    u[v] = 1;
    l[v] = time++;
    for (auto &to : g[v])
        if (!u[to]) {
            dfs(to);
            p[to] = v;
        }
    r[v] = time;
}

void kill() {
    int q;
    scanf("%d", &q);
    for (int i = 0, t, v; i < q; ++i) {
        scanf("%d%d", &t, &v);
        if (t == 1) {
            if (!get(1, 0, n, l[v], r[v])) {
                zero(1, 0, n, l[p[v]]);
            }
            one(1, 0, n, l[v], r[v]);
        }

        if (t == 2) {
            zero(1, 0, n, l[v]);
        }

        if (t == 3) {
            if (get(1, 0, n, l[v], r[v]))
                puts("1\n");
            else
                puts("0\n");
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

    read();
    dfs(1);
    kill();


    return 0;
}