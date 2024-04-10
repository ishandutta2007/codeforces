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

const int S = 31;

int n, m, q, cnt, ecnt, pcnt;
map<int, int> mp[200005];

struct Edge {
    int x, y, l, r, w;
    void init(int xx, int yy, int d, int L) { x = xx, y = yy, w = d, l = L; }
} e[400005];

struct P {
    int x, y;
};
vector<P> vp[200005];

struct Basis {
    int cnt, p[S + 10];
    void insert(int x) {
        for (int i = S; ~i; i--)
            if (x & (1ll << i)) {
                if (p[i] == 0) return p[i] = x, cnt++, void();
                else x ^= p[i];
            }
    }
    int work(int x) {
        for (int i = S; ~i; i--)
            if ((x ^ p[i]) < x) x ^= p[i];
        return x;
    }
} b[20];

struct T { int fa, w, sz; } t[200005];

int find(int x, int &w) {
    while (x != t[x].fa) w ^= t[x].w, x = t[x].fa;
    return x;
}
void merge(int x, int y, int w, int id) {
    if (x == y) return b[id].insert(w);
    if (t[x].sz > t[y].sz) swap(x, y);
    t[x].fa = y, t[x].w = w, t[y].sz += t[x].sz;
}
int qry(int x, int y, int id) {
    int w = 0;
    find(x, w), find(y, w);
    int t;
    return b[id].work(w);
}

int ppcnt;

vector<Edge> te[800005];
void ins_edge(int l, int r, int k, Edge &e) {
    if (e.l > r || e.r < l) return;
    if (e.l <= l && e.r >= r) return ++ppcnt, te[k].push_back(e);
    int mid = l + r >> 1;
    ins_edge(l, mid, k << 1, e), ins_edge(mid + 1, r, k << 1 | 1, e);
}
T stt[800005];
int st[800005], tag[20], top;
void ins(int k, int d) {
    b[d] = b[d - 1], tag[d] = top;
    for (int i = 0; i < te[k].size(); ++i) {
        int x = te[k][i].x, y = te[k][i].y, wx = 0, wy = 0;
        x = find(x, wx), y = find(y, wy);
        st[++top] = x, stt[top] = t[x];
        st[++top] = y, stt[top] = t[y];
        merge(x, y, wx ^ wy ^ te[k][i].w, d);
    }
}
void del(int d) { while (top > tag[d]) t[st[top]] = stt[top], top--; }
void work(int l, int r, int k, int d) {
    ins(k, d);
    if (l == r) {
        for (int i = 0; i < vp[l].size(); ++i) printf("%lld\n", qry(vp[l][i].x, vp[l][i].y, d));
        return del(d);
    }
    int mid = l + r >> 1;
    work(l, mid, k << 1, d + 1), work(mid + 1, r, k << 1 | 1, d + 1), del(d);
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, m);
    for (int i = 1; i <= n; ++i) t[i] = (T){i, 0, 1};
    for (int i = 1, x, y; i <= m; ++i) fr(x, y), e[mp[x][y] = mp[y][x] = i].init(x, y, fr(), 1);
    fr(q), ecnt = m, cnt = 1;
    for (int i = 1, op, x, y; i <= q; ++i) {
        fr(op, x, y);
        if (op == 1) e[mp[x][y] = mp[y][x] = ++ecnt].init(x, y, fr(), ++cnt);
        if (op == 2) e[mp[x][y]].r = cnt++;
        if (op == 3) vp[cnt].push_back((P){x, y});
    }
    for (int i = 1; i <= ecnt; ++i) {
        if (!e[i].r) e[i].r = cnt;
        ins_edge(1, cnt, 1, e[i]);
    }
    work(1, cnt, 1, 1);
    return 0;
}