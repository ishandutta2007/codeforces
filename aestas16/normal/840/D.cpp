// Problem: D. Destiny
// Contest: Codeforces - Codeforces Round #429 (Div. 1)
// URL: https://codeforces.ml/problemset/problem/840/D
// Memory Limit: 512 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

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

const int N = 3e5, M = N << 5;

int n, m, tmp, ptot, a[N + 10], cp[N + 10], rt[N + 10], ls[M + 10], rs[M + 10], sum[M + 10];

void build(int &cur, int l = 1, int r = tmp) {
    cur = ++ptot;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(ls[cur], l, mid), build(rs[cur], mid + 1, r);
}

void modify(int &cur, int u, int pos, int val, int l = 1, int r = tmp) {
    cur = ++ptot, ls[cur] = ls[u], rs[cur] = rs[u], sum[cur] = sum[u] + val;
    if (l == r) return;
    int mid = (l + r) >> 1;
    (pos <= mid) ? modify(ls[cur], ls[u], pos, val, l, mid) : modify(rs[cur], rs[u], pos, val, mid + 1, r);
}

int query(int ql, int qr, int k, int l = 1, int r = tmp) {
    if (l == r) return l;
    int mid = (l + r) >> 1, lsz = sum[ls[qr]] - sum[ls[ql]], rsz = sum[rs[qr]] - sum[rs[ql]], ret;
    if (lsz > k) {
        ret = query(ls[ql], ls[qr], k, l, mid);
        if (ret) return ret;
    }
    if (rsz > k) {
        ret = query(rs[ql], rs[qr], k, mid + 1, r);
        if (ret) return ret;
    }
    return 0;
}

struct OI {
    int RP, score;
} FJOI2021;

int main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    fr(n), fr(m), cp[0] = -1;
    for (int i = 1; i <= n; i++) fr(a[i]), cp[i] = a[i];
    sort(cp + 1, cp + 1 + n), tmp = unique(cp + 1, cp + 1 + n) - cp - 1, build(rt[0]);
    for (int i = 1, x; i <= n; i++) x = lower_bound(cp + 1, cp + tmp + 1, a[i]) - cp, modify(rt[i], rt[i - 1], x, 1);
    for (int i = 1, l, r, k; i <= m; i++) fr(l), fr(r), fr(k), printf("%d\n", cp[query(rt[l - 1], rt[r], (r - l + 1) / k)]);
    return 0;
}