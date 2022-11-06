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

using namespace std;
typedef long long LL;
const int P = 1000000007;

const int V = 2010;

struct Edge{int u, v; LL c;}e[V * V];
bool cmp(Edge x, Edge y) {
    return x.c < y.c;
}

Edge E(int u, int v, LL c) {
    Edge ev;
    ev.u = u;
    ev.v = v;
    ev.c = c;
    return ev;
}

int rt[V];

int f(int x) {
    //printf("F %d %d\n", x, rt[x]);
    if (x != rt[x]) rt[x] = f(rt[x]);
    //printf("FD %d %d\n", x, rt[x]);
    return rt[x];
}

void U(int x, int y) {
    int px = f(x);
    int py = f(y);
    //printf("U %d %d %d %d\n", x, y, px, py);
    rt[py] = px;
}

int x[V], y[V], b[V], c[V];
int id[V];
int ansx[V], ansy[V];
int n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            e[m++] = E(i, n, c[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                e[m++] = E(i, j, (LL) (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (b[i] + b[j]));
            }
        }
        sort(e, e + m, cmp);
        for (int i = 0; i <= n; ++i) rt[i] = i;
        LL cost = 0;
        int an = 0;
        int bn = 0;
        for (int i = 0; i < m; ++i) {
            int u = e[i].u;
            int v = e[i].v;
            //printf("E1 %d %d\n", v, f(v));
            //printf("E %d %d %I64d\n", u, f(u), e[i].c);
            //if (i == 2) break;
            if (f(u) != f(v)) {
                U(u, v);
                cost += e[i].c;
                if (v == n) id[an++] = u;
                else {
                    ansx[bn] = u;
                    ansy[bn++] = v;
                }
            }
        }
        printf("%I64d\n", cost);
        printf("%d\n", an);
        for (int i = 0; i < an; ++i) printf("%d ", id[i] + 1); puts("");
        printf("%d\n", bn);
        for (int i = 0; i < bn; ++i) printf("%d %d\n", ansx[i] + 1, ansy[i] + 1);
    }
    return 0;
}

/*
3
2 3
1 1
3 2
3 2 3
3 2 3

3
2 1
1 2
3 3
23 2 23
3 2 3

*/