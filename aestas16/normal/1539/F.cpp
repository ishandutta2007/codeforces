/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5;

int n, a[N + 10], ans[N + 10];
vector<int> qwq[N + 10];

struct Node {
    int lmsum, rmsum, sum;
    Node() { lmsum = rmsum = sum = 0; }
} t[(N << 2) + 10], null;

Node merge(Node x, Node y) {
    Node ret;
    ret.sum = x.sum + y.sum, ret.lmsum = max(x.lmsum, x.sum + y.lmsum), ret.rmsum = max(y.rmsum, y.sum + x.rmsum);
    return ret;
}

void pushup(int cur) { t[cur] = merge(t[cur << 1], t[cur << 1 | 1]); }

void build(int cur, int l, int r) {
    if (l == r) return t[cur].sum = a[l], t[cur].lmsum = t[cur].rmsum = max(a[l], 0), void();
    int mid = (l + r) >> 1;
    build(cur << 1, l, mid), build(cur << 1 | 1, mid + 1, r), pushup(cur);
}
void modify(int cur, int pos, int v, int l = 1, int r = n) {
    if (l == r) return t[cur].sum = a[pos] = v, t[cur].lmsum = t[cur].rmsum = max(v, 0), void();
    int mid = (l + r) >> 1;
    (pos <= mid) ? (modify(cur << 1, pos, v, l, mid)) : (modify(cur << 1 | 1, pos, v, mid + 1, r));
    pushup(cur);
}
Node query(int cur, int ql, int qr, int l = 1, int r = n) {
    if (ql > r || qr < l) return null;
    if (ql <= l && qr >= r) return t[cur];
    int mid = (l + r) >> 1;
    return merge(query(cur << 1, ql, qr, l, mid), query(cur << 1 | 1, ql, qr, mid + 1, r));
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]), qwq[a[i]].push_back(i);
    for (int i = 1; i <= n; i++) a[i] = -1;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < qwq[i].size(); j++) modify(1, qwq[i][j], 1);
        for (int j = 0; j < qwq[i].size(); j++) {
            int f = query(1, 1, qwq[i][j] - 1).rmsum + query(1, qwq[i][j] + 1, n).lmsum;
            ans[qwq[i][j]] = max(ans[qwq[i][j]], f / 2);
        }
    }
    for (int i = 1; i <= n; i++) a[i] = -1;
    build(1, 1, n);
    for (int i = n; i; i--) {
        for (int j = 0; j < qwq[i].size(); j++) modify(1, qwq[i][j], 1);
        for (int j = 0; j < qwq[i].size(); j++) {
            int f = query(1, 1, qwq[i][j] - 1).rmsum + query(1, qwq[i][j] + 1, n).lmsum;
            ans[qwq[i][j]] = max(ans[qwq[i][j]], (f + 1) / 2);
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return puts(""), 0;
}