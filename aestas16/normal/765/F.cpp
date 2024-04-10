#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &...a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 3e5, INF = 0x3f3f3f3f;

int n, m, qwq, a[N + 10], ans[N + 10];
struct Query { int l, r, id; } Q[N + 10];

struct Node {
    int mn; set<int> s; Node *ch[2];
    void pushup() { mn = min(ch[0]->mn, ch[1]->mn); }
} mem[(N << 2) + 10], *atot = mem, *rt;

void build(Node *&u, int l = 1, int r = n) {
    u = ++atot, u->mn = INF;
    for (int i = l; i <= r; i++) u->s.insert(a[i]);
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u->ch[0], l, mid), build(u->ch[1], mid + 1, r), u->pushup();
}
void modify(Node *u, int pos, int val, int l = 1, int r = n) {
    if (pos < l) return;
    if (r <= pos) {
        auto it = u->s.lower_bound(val);
        if (it != u->s.end()) u->mn = min(u->mn, *it - val);
        if (it != u->s.begin()) u->mn = min(u->mn, val - *prev(it));
        if (u->mn >= qwq) return;
    }
    if (l == r) return qwq = min(qwq, u->mn), void();
    int mid = (l + r) >> 1;
    return modify(u->ch[1], pos, val, mid + 1, r), modify(u->ch[0], pos, val, l, mid), u->pushup(), qwq = min(qwq, u->mn), void();
}
int qmin(Node *u, int pos, int l = 1, int r = n) {
    if (pos > r) return INF;
    if (pos <= l) return u->mn;
    int mid = (l + r) >> 1;
    return min(qmin(u->ch[0], pos, l, mid), qmin(u->ch[1], pos, mid + 1, r));
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]);
    fr(m);
    for (int i = 1; i <= m; i++) fr(Q[i].l, Q[i].r), Q[i].id = i;
    sort(Q + 1, Q + 1 + m, [] (Query a, Query b) { return a.r < b.r; }), build(rt);
    int p = 1;
    while (Q[p].r <= 1) p++;
    for (int i = 2; i <= n; i++) {
        qwq = INF, modify(rt, i - 1, a[i]);
        while (Q[p].r == i) ans[Q[p].id] = qmin(rt, Q[p].l), p++;
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}