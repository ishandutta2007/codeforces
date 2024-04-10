#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

const int V = 100100;

PII e[V];
vector<int> g[V];
int c[V], d[V];

void dd(int u, int f) {
    d[u] = 1;
    int v;
    for (int i = 0; i < g[u].size(); ++i) {
        int j = g[u][i];
        if (e[j].fi == u) v = e[j].se;
        else v = e[j].fi;
        if (f == j) {
            continue;
        }
        dd(v, j);
        d[u]++;
    }
}

int ax[10 * V], ay[10 * V], K;

void add(int x, int y) {
    ax[K] = x;
    ay[K++] = y;
}

void dfs(int u, int f) {
    int v;
    int cur = c[f], way = -1;
    if (d[u] - 1 <= c[f]) {
        cur = c[f] - d[u] + 1;
        //if(d[u] != 1)
        add(u, cur);
        way = -1;
    } else {
        cur = c[f] + 1;
        way = d[u] - 1 - c[f];
    }
    //printf("D %d %d %d %d %d\n", u, d[u], c[f], cur, way);
    for (int i = 0; i < g[u].size(); ++i) {
        int j = g[u][i];
        if (e[j].fi == u) v = e[j].se;
        else v = e[j].fi;
        if (f == j) {
            continue;
        }
        c[j] = cur;
        add(v, cur + 1);
        //printf("%d %d\n", v, cur + 1);
        dfs(v, j);
        if (way >= 0) {
            cur++;
            --way;
        } else {
            ++cur;
        }
        if (way == 0) {
            add(u, 0);
            cur = 0;
            way = -1;
        }
    }
    //if (d[u] == 1) {
    //    add(u, c[f]);
        //printf("%d %d\n", u, c[f]);
    //}
    if (f != 0) {
        if (e[f].fi == u) v = e[f].se;
        else v = e[f].fi;
        if (cur != c[f]) {
            add(u, c[f]);
        }
        add(v, c[f] + 1);
        //printf("%d %d\n", v, c[f] + 1);
    }
}

int n, u, v;
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            e[i] = MP(u, v);
            g[u].PB(i);
            g[v].PB(i);
        }
        memset(d, 0, sizeof(d));
        K = 0;
        dd(1, 0);
        c[0] = -1;
        add(1, 0);
        //printf("%d %d\n", 1, 0);
        dfs(1, 0);
        printf("%d\n", K);
        for (int i = 0; i < K; ++i) printf("%d %d\n", ax[i], ay[i]);
    }
    return 0;
}

/*
5
1 2
2 3
2 4
4 5
*/