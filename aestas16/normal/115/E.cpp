/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5, INF = 0x7f7f7f7f7f7f7f7f;

struct Query {
    int p, val;
    Query(int x, int y) { p = x, val = y; }
};

int n, m, Max[(N << 2) + 10], atag[(N << 2) + 10], a[N + 10], f[N + 10];
vector<Query> qwq[N + 10];

void pushup(int cur) { Max[cur] = max(Max[cur << 1], Max[cur << 1 | 1]); }

void revise(int cur, int val) { Max[cur] += val, atag[cur] += val; }

void pushdown(int cur) {
    if (atag[cur] == 0) return;
    revise(cur << 1, atag[cur]), revise(cur << 1 | 1, atag[cur]), atag[cur] = 0;
}

void add(int cur, int l, int r, int x, int y, int val) {
    if (x <= l && r <= y) return revise(cur, val);
    pushdown(cur);
    int mid = (l + r) >> 1;
    if (x <= mid) add(cur << 1, l, mid, x, y, val);
    if (mid < y) add(cur << 1 | 1, mid + 1, r, x, y, val);
    pushup(cur);
}

int query(int cur, int l, int r, int x, int y) {
    if (x <= l && r <= y) return Max[cur];
    pushdown(cur);
    int mid = (l + r) >> 1, ret = -INF;
    if (x <= mid) ret = query(cur << 1, l, mid, x, y);
    if (mid < y) ret = max(ret, query(cur << 1 | 1, mid + 1, r, x, y));
    return ret;
}

void modify(int cur, int l, int r, int pos, int val) {
    if (l == r) return (void)(atag[cur] = 0, Max[cur] = val);
    pushdown(cur);
    int mid = (l + r) >> 1;
    if (pos <= mid)
        modify(cur << 1, l, mid, pos, val);
    else
        modify(cur << 1 | 1, mid + 1, r, pos, val);
    pushup(cur);
}

struct OI {
    int RP, score;
} FJOI2021;

signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    fr(n), fr(m);
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = 1, x, y, v; i <= m; i++) fr(x), fr(y), fr(v), qwq[y].push_back(Query(x, v));
    for (int i = 1; i <= n; i++) {
        add(1, 0, n, 0, i - 1, -a[i]);
        for (int j = 0; j < qwq[i].size(); j++) {
            int p = qwq[i][j].p, val = qwq[i][j].val;
            add(1, 0, n, 0, p - 1, val);
        }
        f[i] = max(f[i - 1], query(1, 0, n, 0, i - 1)), modify(1, 0, n, i, f[i]);
    }
    return printf("%lld\n", f[n]), 0;
}