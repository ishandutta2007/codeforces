#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 3e5;

int n, m, top, pos, odd, ans[N + 10], fa[N + 10], sz[N + 10];
struct Edge { int x, y, v, id; } e[N + 10];
struct Node { int x, y, v; } stk[(N << 2) + 10];
vector<int> st[(N << 2) + 10];

int find(int u) { return fa[u] == u ? u : find(fa[u]); }
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    stk[++top] = {x, sz[x], 0}, fa[x] = y;
    if ((sz[x] % 2 == 1) && (sz[y] % 2 == 1)) odd -= 2, stk[top].v = 2;
    sz[y] += sz[x];
}

void modify(int u, int ql, int qr, int val, int l = 1, int r = m) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) return st[u].push_back(val), void();
    int mid = (l + r) >> 1;
    modify(u << 1, ql, qr, val, l, mid), modify(u << 1 | 1, ql, qr, val, mid + 1, r);
}

void stdc(int u, int l = 1, int r = m) {
    int lsttop = top;
    for (auto i : st[u]) merge(e[i].x, e[i].y);
    if (l == r) {
        while (1) {
            if (odd == 0 || pos == m) break;
            if (e[pos + 1].id <= l) merge(e[pos + 1].x, e[pos + 1].y), modify(1, e[pos + 1].id, l - 1, pos + 1);
            pos++;
        }
        if (odd == 0) ans[l] = e[pos].v;
        else ans[l] = -1;
    }
    else { int mid = (l + r) >> 1; stdc(u << 1 | 1, mid + 1, r), stdc(u << 1, l, mid); }
    while (top > lsttop) { int x = stk[top].x; sz[fa[x]] -= stk[top].y, fa[x] = x, odd += stk[top].v, top--; }
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, m), odd = n;
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++) fr(e[i].x, e[i].y, e[i].v), e[i].id = i;
    sort(e + 1, e + m + 1, [] (Edge a, Edge b) { return a.v < b.v; }), stdc(1);
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}