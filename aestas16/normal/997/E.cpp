#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &...a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 3e5;

int n, q, top1, top2, a[N + 10], stk1[N + 10], stk2[N + 10], ans[N + 10];
struct Query { int l, r, id; } Q[N + 10];
struct Node {
    int mn, cnt, atag, tag, ans; Node *ch[2];
    void add(int val) { mn += val, atag += val; }
    void revise(int val) { ans += val * cnt, tag += val; }
    void pushup() {
        mn = min(ch[0]->mn, ch[1]->mn), cnt = 0, ans = ch[0]->ans + ch[1]->ans;
        if (mn == ch[0]->mn) cnt += ch[0]->cnt;
        if (mn == ch[1]->mn) cnt += ch[1]->cnt;
    }
    void pushdown() {
        if (atag) ch[0]->add(atag), ch[1]->add(atag), atag = 0;
        if (tag) {
            if (mn == ch[0]->mn) ch[0]->revise(tag);
            if (mn == ch[1]->mn) ch[1]->revise(tag);
            tag = 0;
        }
    }
} mem[(N << 2) + 10], *atot = mem, *rt;

void build(Node *&u, int l = 1, int r = n) {
    u = ++atot, u->mn = l, u->cnt = 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u->ch[0], l, mid), build(u->ch[1], mid + 1, r);
}
void modify(Node *u, int ql, int qr, int val, int l = 1, int r = n) {
    if (ql > r || qr < l) return;
    if (ql <= l && qr >= r) return u->add(val);
    int mid = (l + r) >> 1;
    u->pushdown(), modify(u->ch[0], ql, qr, val, l, mid), modify(u->ch[1], ql, qr, val, mid + 1, r), u->pushup();
}
int query(Node *u, int ql, int qr, int l = 1, int r = n) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) return u->ans;
    int mid = (l + r) >> 1;
    return u->pushdown(), query(u->ch[0], ql, qr, l, mid) + query(u->ch[1], ql, qr, mid + 1, r);
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]);
    fr(q);
    for (int i = 1; i <= q; i++) fr(Q[i].l, Q[i].r), Q[i].id = i;
    sort(Q + 1, Q + 1 + q, [] (Query a, Query b) { return a.r < b.r; });
    build(rt);
    for (int i = 1, j = 1; i <= n; i++) {
        rt->add(-1);
        while (top1 && a[i] > a[stk1[top1]]) modify(rt, stk1[top1 - 1] + 1, stk1[top1], a[i] - a[stk1[top1]]), top1--;
        while (top2 && a[i] < a[stk2[top2]]) modify(rt, stk2[top2 - 1] + 1, stk2[top2], a[stk2[top2]] - a[i]), top2--;
        stk1[++top1] = i, stk2[++top2] = i, rt->revise(1);
        while (j <= q && Q[j].r == i) ans[Q[j].id] = query(rt, Q[j].l, i), j++;
    }
    for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
    return 0;
}