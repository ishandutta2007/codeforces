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

const int N = 1e5, 
          B = 3926, iB = 467112991, P = 999392699;

int n, top;

namespace Hash {
    int _Pow[N * 2 + 10], *Pow = _Pow + N + 5;
    void Init(int up) {
        Pow[0] = 1;
        for (int i = 1; i <= up; i++) Pow[i] = Pow[i - 1] * B % P, Pow[-i] = Pow[-i + 1] * iB % P;
    }
    struct str {
        int val, len;
        str() { val = len = 0; }
        str(int v) { val = v, len = 1; }
        str(int v, int l) : val(v), len(l) {}
        bool operator == (str rhs) { return val == rhs.val && len == rhs.len; }
        str operator + (str rhs) { return str((val + rhs.val * Pow[len] % P) % P, len + rhs.len); }
        str operator - (str rhs) { return str((val - rhs.val + P) * Pow[-rhs.len] % P, len - rhs.len); }
    } arr[50];
} // namespace Hash
using namespace Hash;

struct Node {
    str sl, sr; bool vis; Node *ch[2];
    Node() { vis = 0; }
    void Init(int x) {
        vis = 0, sl = sr = str();
        if (x > 0) sr = str(x);
        else sl = str(-x);
    }
} mem[(N << 2) + 10], *atot = mem, *rt, *stk[50];

str getl(Node *u, int k) {
    if (k == 0) return str();
    if (k == u->sl.len) return u->sl;
    if (k <= u->ch[0]->sl.len) return getl(u->ch[0], k);
    return u->ch[0]->sl + (getl(u->ch[1], k - u->ch[0]->sl.len + u->ch[0]->sr.len) - u->ch[0]->sr);
}
str getr(Node *u, int k) {
    if (k == 0) return str();
    if (k == u->sr.len) return u->sr;
    if (k <= u->ch[1]->sr.len) return getr(u->ch[1], k);
    return u->ch[1]->sr + (getr(u->ch[0], k - u->ch[1]->sr.len + u->ch[1]->sl.len) - u->ch[1]->sl);
}
void pushup(Node *u) {
    if (u->ch[0]->vis || u->ch[1]->vis) return u->vis = 1, void();
    u->vis = 0, u->sl = u->ch[0]->sl, u->sr = u->ch[1]->sr;
    if (u->ch[0]->sr.len <= u->ch[1]->sl.len) {
        if (u->ch[0]->sr == getl(u->ch[1], u->ch[0]->sr.len)) u->sl = u->sl + (u->ch[1]->sl - u->ch[0]->sr);
        else u->vis = 1;
    } else {
        if (u->ch[1]->sl == getr(u->ch[0], u->ch[1]->sl.len)) u->sr = u->sr + (u->ch[0]->sr - u->ch[1]->sl);
        else u->vis = 1;
    }
}

void build(Node *&u, int l = 1, int r = n) {
    // printf("[%d, %d]\n", l, r);
    u = ++atot;
    if (l == r) return u->Init(fr());
    int mid = (l + r) >> 1;
    build(u->ch[0], l, mid), build(u->ch[1], mid + 1, r), pushup(u);
    // printf("[%d, %d]\n", l, r);
}
void modify(Node *u, int pos, int val, int l = 1, int r = n) {
    if (l == r) return u->Init(val);
    int mid = (l + r) >> 1;
    (pos <= mid) ? modify(u->ch[0], pos, val, l, mid) : modify(u->ch[1], pos, val, mid + 1, r);
    pushup(u);
}
void query(Node *u, int ql, int qr, int l = 1, int r = n) {
    if (ql > r || qr < l) return;
    if (ql <= l && qr >= r) return stk[++top] = u, void();
    int mid = (l + r) >> 1;
    query(u->ch[0], ql, qr, l, mid), query(u->ch[1], ql, qr, mid + 1, r);
}

str get(int i, int k) {
    if (k == 0) return str();
    if (k == arr[i].len) return arr[i];
    if (k <= stk[i]->sr.len) return getr(stk[i], k);
    return stk[i]->sr + (get(i - 1, k - stk[i]->sr.len + stk[i]->sl.len) - stk[i]->sl);
}

bool Query(int l, int r) {
    top = 0, query(rt, l, r);
    // printf("%d\n", stk[1]->sl.len);
    for (int i = 1; i <= top; i++) {
        if (stk[i]->vis) return 0;
        if (arr[i - 1].len < stk[i]->sl.len) return 0;
        if (stk[i]->sl == get(i - 1, stk[i]->sl.len)) arr[i] = stk[i]->sr + (arr[i - 1] - stk[i]->sl);
        else return 0;
    }
    return arr[top].len == 0;
}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n), fr(), Init(n), build(rt);
    for (int q = fr(), op, x, y; q--;) {
        fr(op, x, y);
        if (op == 1) modify(rt, x, y);
        else puts(Query(x, y) ? "Yes" : "No");
    }
    return 0;
}