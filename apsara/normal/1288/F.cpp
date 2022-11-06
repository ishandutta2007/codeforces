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
const int oo = 1000000000;
const int V = 510;

struct Edge{
    int v, ne, c, w;
}e[1001000];
int p[V], K;

void add_r(int u, int v, int c, int w) {
    e[K].v = v;
    e[K].c = c;
    e[K].w = w;
    e[K].ne = p[u];
    p[u] = K++;
}

void add(int u, int v, int c, int w) {
    //printf("Add %d %d %d %d\n", u, v, c, w);
    add_r(u, v, c, w);
    add_r(v, u, 0, -w);
}

int d[V], vis[V], q[V], pre[V];

bool spfa(int N, int st, int ed) {
    for (int i = 0; i < N; ++i) {
        d[i] = oo;
        vis[i] = 0;
        pre[i] = -1;
    }
    int top = 0, tail = 0;
    vis[st] = 1;
    d[st] = 0;
    q[++tail] = st;
    while (top != tail) {
        top = (top + 1) % V;
        int u = q[top];
        vis[u] = 0;
        for (int i = p[u]; i != -1; i = e[i].ne) {
            int v = e[i].v;
            if(e[i].c > 0 && d[v] - e[i].w > d[u]) {
                d[v] = d[u] + e[i].w;
                pre[v] = i;
                if (!vis[v]) {
                    vis[v] = 1;
                    tail = (tail + 1) % V;
                    q[tail] = v;
                }
            }
        }
    }
    return d[ed] != oo;
}

int flow;

int mcmf(int N, int st, int ed) {
    int cost = 0;
    flow = 0;
    while (spfa(N, st, ed)) {
        //printf("mcmf %d %d\n", flow, d[ed]);
        cost += d[ed];
        int u = ed;
        while (u != st) {
            e[pre[u]].c--;
            e[pre[u] ^ 1].c++;
            u = e[pre[u] ^ 1].v;
        }
        ++flow;
    }
    //printf("MCMF res %d %d\n", flow, cost);
    return cost;
}

struct Ap{
    int u, v, lo, up, w;
}a[100100];
int an;

int s[V];

void solve(int N, int st, int ed, int m_start, int m_end) {
    for (int i = 0; i < N + 2; ++i) p[i] = -1; K = 0;
    for (int i = 0; i < N; ++i) s[i] = 0;
    for (int i = 0; i < an; ++i) {
        s[a[i].u] -= a[i].lo;
        s[a[i].v] += a[i].lo;
        add(a[i].u, a[i].v, a[i].up - a[i].lo, a[i].w);
    }
    int ss = N;
    int tt = N + 1;
    add(ed, st, oo, 0);
    int s_lo = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] > 0) {
            add(ss, i, s[i], 0);
            s_lo += s[i];
        } else if (s[i] < 0) {
            add(i, tt, -s[i], 0);
        }
    }
    int res = mcmf(N + 2, ss, tt);
    if (flow != s_lo) {
        puts("-1");
        return;
    }
    printf("%d\n", res);
    for (int i = m_start; i < m_end; i += 2) {
        if (e[i * 2]. c == 0 && e[i * 2 + 2].c == 1) printf("R");
        else if (e[i * 2]. c == 1 && e[i * 2 + 2].c == 0) printf("B");
        else printf("U");
    }
    puts("");
}

void adde(int u, int v, int lo, int up, int w) {
    //printf("adde %d %d %d %d %d\n", u, v, lo, up, w);
    a[an].u = u;
    a[an].v = v;
    a[an].lo = lo;
    a[an].up = up;
    a[an++].w = w;
}

int n1, n2, m, R, B, u, v;
char ss[V];
int main() {
    while (~scanf("%d%d%d%d%d", &n1, &n2, &m, &R, &B)) {
        int N = n1 + n2 + 2;
        int st = N - 2;
        int ed = N - 1;
        an = 0;
        scanf("%s", ss);
        for (int i = 0; i < n1; ++i) {
            if (ss[i] == 'R') {
                adde(st, i, 1, oo, 0);
            } else if (ss[i] == 'B') {
                adde(i, ed, 1, oo, 0);
            } else {
                adde(st, i, 0, oo, 0);
                adde(i, ed, 0, oo, 0);
            }
        }
        scanf("%s", ss);
        for (int i = 0; i < n2; ++i) {
            if (ss[i] == 'R') {
                adde(n1 + i, ed, 1, oo, 0);
            } else if (ss[i] == 'B') {
                adde(st, n1 + i, 1, oo, 0);
            } else {
                adde(n1 + i, ed, 0, oo, 0);
                adde(st, n1 + i, 0, oo, 0);
            }
        }
        int m_start = an;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            u--;v--;
            v += n1;
            adde(u, v, 0, 1, R);
            adde(v, u, 0, 1, B);
        }
        solve(N, st, ed, m_start, m_start + m * 2);
    }
    return 0;
}

/*
3 2 6 10 15
RRB
UB
3 2
2 2
1 2
1 1
2 1
1 1

3 1 3 4 5
RRR
B
2 1
1 1
3 1

3 1 3 4 5
URU
B
2 1
1 1
3 1

*/