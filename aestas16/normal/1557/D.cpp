// 392699

#include <bits/stdc++.h>

using namespace std;

#ifdef Aestas16
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 0
#endif

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

#define now seg[cur]
#define ls cur << 1
#define rs cur << 1 | 1
#define lch seg[ls]
#define rch seg[rs]

const int N = 12e5, INF = 0x7f7f7f7f;

int n, m;
bool vis[N + 10];
pair<int, int> f[N + 10];
vector<pair<int, int> > a[N + 10];
vector<int> qwq;

struct Node {
    int l, r;
    pair<int, int> ctag, Max;
    Node(int l = 0, int r = 0) : l(l), r(r) { ctag = Max = pair<int, int>(0, 0); }
} seg[(N << 2) + 10];

void pushup(int cur) { now.Max = max(lch.Max, rch.Max); }
void revisec(int cur, pair<int, int> val) { now.ctag = now.Max = val; }
void pushdown(int cur) {
    if (now.ctag != pair<int, int>(0, 0)) revisec(ls, now.ctag), revisec(rs, now.ctag), now.ctag = pair<int, int>(0, 0);
}
void build(int cur, int l, int r) {
    now = Node(l, r);
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(ls, l, mid), build(rs, mid + 1, r), pushup(cur);
}
void modify(int cur, int l, int r, pair<int, int> val) {
    if (now.l > r || now.r < l) return;
    if (now.l >= l && now.r <= r) return revisec(cur, val);
    pushdown(cur), modify(ls, l, r, val), modify(rs, l, r, val), pushup(cur);
}
pair<int, int> query(int cur, int l, int r) {
    if (now.l > r || now.r < l) return pair<int, int>(0, 0);
    if (now.l >= l && now.r <= r) return now.Max;
    pushdown(cur);
    return max(query(ls, l, r), query(rs, l, r));
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n, m);
    for (int i = 1, j, l, r; i <= m; i++) fr(j, l, r), a[j].emplace_back(l, r), qwq.push_back(l), qwq.push_back(l + 1), qwq.push_back(r), qwq.push_back(r + 1);
    sort(qwq.begin(), qwq.end()), qwq.erase(unique(qwq.begin(), qwq.end()), qwq.end());
    for (int i = 1; i <= n; i++)
        for (auto &j : a[i])
            j.first = lower_bound(qwq.begin(), qwq.end(), j.first) - qwq.begin() + 1, 
            j.second = lower_bound(qwq.begin(), qwq.end(), j.second) - qwq.begin() + 1;
    build(1, 1, N);
    for (int i = 1; i <= n; i++) {
        for (auto j : a[i]) {
            pair<int, int> tmp = query(1, j.first, j.second);
            tmp.first++, f[i] = max(f[i], tmp);
        }
        for (auto j : a[i]) {
            pair<int, int> tmp = f[i];
            tmp.second = i, modify(1, j.first, j.second, tmp);
        }
    }
    int tot = 0;
    for (int i = max_element(f + 1, f + 1 + n) - f; i; i = f[i].second) vis[i] = 1, tot++;
    printf("%d\n", n - tot);
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0) printf("%d ", i);
    puts("");
    return 0;
}