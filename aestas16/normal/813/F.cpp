#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e5, M = N << 2;

int n, m, top, fa[N + 10], sz[N + 10];
struct Edge { int x, y; } e[N + 10];
struct Node { int x, y, val; } stk[M + 10];
vector<int> qwq[M + 10];
map<int, int> E[N + 10];

int find(int u) { return fa[u] == u ? u : find(fa[u]); }
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (sz[x] > sz[y]) swap(x, y);
    stk[++top] = {x, y, sz[x]}, fa[x] = y, sz[y] += sz[x];
}

void update(int u, int ql, int qr, int val, int l = 1, int r = m) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) return qwq[u].push_back(val), void();
    int mid = (l + r) >> 1;
    update(u << 1, ql, qr, val, l, mid), update(u << 1 | 1, ql, qr, val, mid + 1, r);
}

void sgtdiv(int u, int l = 1, int r = m) {
    bool ans = 1; int lsttop = top;
    for (int i = 0; i < qwq[u].size(); i++) {
        int x = find(e[qwq[u][i]].x), y = find(e[qwq[u][i]].y);
        if (x == y) {
            for (int k = l; k <= r; k++) puts("NO");
            ans = 0; break;
        }
        merge(e[qwq[u][i]].x, e[qwq[u][i]].y + n), merge(e[qwq[u][i]].y, e[qwq[u][i]].x + n);
    }
    if (ans) {
        if (l == r) puts("YES");
        else { int mid = (l + r) >> 1; sgtdiv(u << 1, l, mid), sgtdiv(u << 1 | 1, mid + 1, r); }
    }
    while (top > lsttop) sz[fa[stk[top].x]] -= stk[top].val, fa[stk[top].x] = stk[top].x, top--;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n), fr(m);
    for (int i = 1, l, r; i <= m; i++) {
        fr(e[i].x), fr(e[i].y);
        if (E[e[i].x][e[i].y]) update(1, E[e[i].x][e[i].y], i - 1, i), E[e[i].x][e[i].y] = E[e[i].y][e[i].x] = 0;
        else E[e[i].x][e[i].y] = E[e[i].y][e[i].x] = i;
    }
    for (int i = 1; i <= n; i++)
        for (auto j : E[i]) if (j.second) update(1, j.second, m, j.second);
    for (int i = 1; i <= n * 2; i++) fa[i] = i, sz[i] = 1;
    return sgtdiv(1), 0;
}