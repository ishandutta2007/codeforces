#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 5e5, M = N << 2;

int n, m, k, q, top, a[N + 10], c[N + 10], p[N + 10], fa[52][(N << 1) + 10], sz[52][(N << 1) + 10];
struct Edge { int x, y; } e[N + 10];
struct Node { int x, y, c; } stk[(N << 2) + 10];
vector<int> st[M + 10];

int find(int c, int u) { return fa[c][u] == u ? u : find(c, fa[c][u]); }
void merge(int c, int x, int y) {
    x = find(c, x), y = find(c, y);
    if (x == y) return;
    if (sz[c][x] > sz[c][y]) swap(x, y);
    stk[++top] = {x, sz[c][x], c}, fa[c][x] = y, sz[c][y] += sz[c][x];
}

void modify(int u, int ql, int qr, int val, int l = 1, int r = q) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) return st[u].push_back(val), void();
    int mid = (l + r) >> 1;
    modify(u << 1, ql, qr, val, l, mid), modify(u << 1 | 1, ql, qr, val, mid + 1, r);
}

void stdc(int u, int l = 1, int r = q) {
    int lsttop = top;
    for (auto i : st[u]) {
        int j = a[i];
        if (c[i]) merge(c[i], e[j].x, e[j].y + n), merge(c[i], e[j].y, e[j].x + n);
    }
    if (l == r) {
        int i = a[l];
        if (find(c[l], e[i].x) == find(c[l], e[i].y)) puts("NO"), c[l] = p[i];
        else puts("YES"), p[i] = c[l];
    }
    else { int mid = (l + r) >> 1; stdc(u << 1, l, mid), stdc(u << 1 | 1, mid + 1, r); }
    while (top > lsttop) { int c = stk[top].c, x = stk[top].x; sz[c][fa[c][x]] -= stk[top].y, fa[c][x] = x, top--; }
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, m, k, q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++) fa[j][i] = i, fa[j][i + n] = i + n, sz[j][i] = sz[j][i + n] = 1;
    for (int i = 1; i <= m; i++) fr(e[i].x), fr(e[i].y), p[i] = q + 1;
    for (int i = 1; i <= q; i++) fr(a[i], c[i]);
    for (int i = q; i; i--) {
        if (i < p[a[i]] - 1) modify(1, i + 1, p[a[i]] - 1, i);
        p[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) p[i] = 0;
    return stdc(1), 0;
}