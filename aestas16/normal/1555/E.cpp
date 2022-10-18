// 392699

#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 4e6;

int n, m, atag[N + 10], mn[N + 10];

struct Node {
    int l, r, w;
    bool operator < (const Node &rhs) const { return w < rhs.w; }
} a[N + 10];

void pushup(int cur) { mn[cur] = min(mn[cur << 1], mn[cur << 1 | 1]); }
void add(int cur, int val) { atag[cur] += val, mn[cur] += val; }
void pushdown(int cur) {
    if (atag[cur]) add(cur << 1, atag[cur]), add(cur << 1 | 1, atag[cur]), atag[cur] = 0;
}
void modify(int cur, int l, int r, int ql, int qr, int val) {
    if (ql > r || qr < l) return;
    if (ql <= l && qr >= r) return add(cur, val);
    int mid = (l + r) >> 1;
    pushdown(cur), modify(cur << 1, l, mid, ql, qr, val), modify(cur << 1 | 1, mid + 1, r, ql, qr, val), pushup(cur);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n, m), m--;
    for (int i = 1; i <= n; i++) fr(a[i].l, a[i].r, a[i].w), a[i].r--;
    sort(a + 1, a + n + 1);
    int pl = 1, pr = 0, tmp = 2e9;
    while (pr < n && mn[1] == 0) pr++, modify(1, 1, m, a[pr].l, a[pr].r, 1);
    tmp = min(tmp, a[pr].w - a[pl].w);
    for (pl++; pl <= n; pl++) {
        modify(1, 1, m, a[pl - 1].l, a[pl - 1].r, -1);
        while (pr < n && mn[1] == 0) pr++, modify(1, 1, m, a[pr].l, a[pr].r, 1);
        if (mn[1] != 0) tmp = min(tmp, a[pr].w - a[pl].w);
    }
    printf("%d\n", tmp);
    return 0;
}