#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e5;

int n, m;

struct Node {
    int sum, atag, l, r; Node *ch[2];
    void pushup() { sum = ch[0]->sum + ch[1]->sum; }
    void revise(int val) { atag += val, sum += (r - l + 1) * val; }
    void pushdown() { if (atag) ch[0]->revise(atag), ch[1]->revise(atag), atag = 0; }
} mem[(N << 2) + 10], *atot = mem, *rt;

void build(Node *&u, int l = 1, int r = n) {
    u = ++atot, u->l = l, u->r = r;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(u->ch[0], l, mid), build(u->ch[1], mid + 1, r), u->pushup();
}
void modify(Node *u, int ql, int qr, int val, int l = 1, int r = n) {
    if (ql > r || qr < l) return;
    if (ql <= l && qr >= r) return u->revise(val);
    int mid = (l + r) >> 1;
    u->pushdown(), modify(u->ch[0], ql, qr, val, l, mid), modify(u->ch[1], ql, qr, val, mid + 1, r), u->pushup();
}
int qsum(Node *u, int ql, int qr, int l = 1, int r = n) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) return u->sum;
    int mid = (l + r) >> 1;
    return u->pushdown(), qsum(u->ch[0], ql, qr, l, mid) + qsum(u->ch[1], ql, qr, mid + 1, r);
}

struct CNode {
    mutable int l, r, v;
    CNode(int l, int r = -1, int v = 0) : l(l), r(r), v(v) {}
    bool operator < (const CNode &rhs) const { return l < rhs.l; }
};
set<CNode> s;
auto split(int pos) {
    auto p = s.lower_bound(CNode(pos));
    if (p != s.end() && p->l == pos) return p;
    p--; int l = p->l, r = p->r, v = p->v;
    return s.erase(p), s.insert(CNode(l, pos - 1, v)), s.insert(CNode(pos, r, v)).first;
}
void assign(int l, int r, int v) {
    auto pr = split(r + 1), pl = split(l);
    for (auto i = pl; i != pr; i++) modify(rt, i->l, i->r, abs(v - i->v));
    s.erase(pl, pr), s.insert(CNode(l, r, v));
}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n, m), build(rt);
    for (int i = 1; i <= n; i++) s.insert(CNode(i, i, i));
    for (int op, l, r, x, _ = 1; _ <= m; _++) {
        fr(op, l, r);
        if (op == 1) fr(x), assign(l, r, x);
        else printf("%lld\n", qsum(rt, l, r));
    }
    return 0;
}