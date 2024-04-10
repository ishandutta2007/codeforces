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

const int N = 4e4, P = 1e9 + 7;

int n, k, q, atot, Q[N + 10], p[N + 10], lst[N + 10];
struct Element { int v, w; } a[N + 10];
vector<int> f, st[(N << 2) + 10];

void modify(int u, int ql, int qr, int val, int l = 1, int r = q) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) return st[u].push_back(val), void();
    int mid = (l + r) >> 1;
    modify(u << 1, ql, qr, val, l, mid), modify(u << 1 | 1, ql, qr, val, mid + 1, r);
}

void stdc(int u, int l = 1, int r = q) {
    for (auto i : st[u])
        for (int j = k; ~j; j--) if (j + a[i].w <= k) f[j + a[i].w] = max(f[j + a[i].w], f[j] + a[i].v);
    if (l == r) {
        if (Q[l]) {
            int ans = 0;
            for (int i = 1; i <= k; i++) ans = (ans + f[i] * p[i - 1] % P) % P;
            printf("%lld\n", ans);
        }
        return ;
    }
    int mid = (l + r) >> 1; vector<int> g = f;
    stdc(u << 1, l, mid), f = g, stdc(u << 1 | 1, mid + 1, r);
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    p[0] = 1, p[1] = 1e7 + 19, fr(n, k), f.resize(k + 10);
    for (int i = 2; i <= k; i++) p[i] = p[i - 1] * p[1] % P;
    for (int i = 1; i <= n; i++) fr(a[i].v, a[i].w), atot++, lst[i] = 1;
    fr(q);
    for (int op, v, w, _ = 1; _ <= q; _++) {
        fr(op);
        if (op == 1) fr(v, w), a[++atot] = {v, w}, lst[atot] = _;
        else if (op == 2) fr(v), modify(1, lst[v], _, v), lst[v] = 0;
        else Q[_] = 1;
    }
    for (int i = 1; i <= atot; i++)
        if (lst[i]) modify(1, lst[i], q, i);
    stdc(1);
    return 0;
}