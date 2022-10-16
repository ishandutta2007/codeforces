// naive problem
#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e6 + 5, E = 4e6 + 5;

struct List {
    int tot, fst[N], nxt[E], to[E];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int v) {
        nxt[tot] = fst[u]; to[tot] = v; fst[u] = tot++;
    }
    inline void link(int u, int v) {
        insert(u, v); insert(v ^ 1, u ^ 1);
    }
} e;

int n, m, m0, m1, k, c, tms, vol, dfn[N], low[N], stc[N], col[N];
bool ins[N];

inline int yes(int u) { return u << 1; }
inline int no(int u) { return u << 1 | 1; }

void tarjan(int u) {
    dfn[u] = low[u] = tms++;
    int pos = vol; stc[vol++] = u; ins[u] = true;
    for (int i = e.fst[u]; ~i; i = e.nxt[i]) {
        int v = e.to[i];
        if (dfn[v] == -1) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        while (vol > pos) {
            int v = stc[--vol];
            col[v] = c; ins[v] = false;
        } c++;
    }
}

bool solve() {
    for (int i = 0; i <= no(n + m); i++) { dfn[i] = -1; }
    for (int i = 0; i <= no(n + m); i++) {
        if (dfn[i] == -1) { tarjan(i); }
    }
    for (int i = 0; i <= n + m; i++) {
        if (col[yes(i)] == col[no(i)]) { return false; }
    } return true;
}

int main() {
    m0 = read(); n = read(); m = read(); m1 = read();
    for (int i = 0; i < m0; i++) {
        int u = read(), v = read(); u--; v--;
        e.link(no(u), yes(v));
    }
    for (int i = 0; i < m; i++) {
        e.link(yes(n + i), yes(n + i + 1));
    } e.link(yes(n), no(n));
    for (int i = 0; i < n; i++) {
        int l = read(), r = read();
        e.link(yes(i), no(n + l - 1));
        e.link(yes(i), yes(n + r));
    }
    for (int i = 0; i < m1; i++) {
        int u = read(), v = read(); u--; v--;
        e.link(yes(u), no(v));
    }
    if (solve()) {
        for (int i = 0; i < n; i++) {
            if (col[yes(i)] < col[no(i)]) { k++; }
        }
        for (int i = 1; i <= m; i++) {
            if (col[yes(n + i)] < col[no(n + i)]) {
                printf("%d %d\n", k, i); break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (col[yes(i)] < col[no(i)]) { printf("%d ", i + 1); }
        }
    } else {
        puts("-1");
    }
    return 0;
}