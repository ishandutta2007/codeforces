#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int nm[444444];
int rnm[444444];
int sz[444444];
int c[444444];

vector<int> g[444444];

int cnm = 0;

int dfs(int v, int p) {
    nm[v] = cnm++;
    int csz = 1;
    for (int i : g[v]) {
        if (i != p) {
            csz += dfs(i, v);
        }
    }
    return sz[v] = csz;
}

struct SegmentTree {
    lint* a;
    lint* st;
    int n;

    SegmentTree(int n) {
        this->n = n;
        a = new lint[4 * n];
        st = new lint[4 * n];
        memset(st, -1, sizeof(lint) * 4 * n);
        build(0, 0, n);
    }

    void push(int i, int l, int r) {
        if (st[i] == -1) {
            return;
        }
        a[i] = st[i];
        if (l + 1 != r) {
            st[i * 2 + 1] = st[i];
            st[i * 2 + 2] = st[i];
        }
        st[i] = -1;
    }

    void build(int i, int l, int r) {
        if (l + 1 == r) {
            int cc = c[rnm[l]];
            a[i] = 1LL << cc;
        } else {
            int m = (l + r) >> 1;
            build(i * 2 + 1, l, m);
            build(i * 2 + 2, m, r);
            a[i] = a[i * 2 + 1] | a[i * 2 + 2];
        }
    }

    lint get(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (l >= qr || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return a[i];
        }
        int m = (l + r) >> 1;
        return get(i * 2 + 1, l, m, ql, qr) | get(i * 2 + 2, m, r, ql, qr);
    }

    void set(int i, int l, int r, int ql, int qr, lint x) {
        push(i, l, r);
        if (l >= qr || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            st[i] = x;
            push(i, l, r);
            return;
        }
        int m = (l + r) >> 1;
        set(i * 2 + 1, l, m, ql, qr, x);
        set(i * 2 + 2, m, r, ql, qr, x);
        a[i] = a[i * 2 + 1] | a[i * 2 + 2];
    }
};

int popcount(lint x) {
    int res = 0;
    while (x) {
        res++;
        x &= x - 1;
    }
    return res;
}

int main() {
    sciid(n, m);
    rea(c, n);
    for (int i = 1; i < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        rnm[nm[i]] = i;
    }


    SegmentTree st(n);

    for (int i = 0; i < m; i++) {
        scid(t);
        if (t == 1) {
            sciid(v, k);
            --v;
            st.set(0, 0, n, nm[v], nm[v] + sz[v], 1LL << k);
        } else {
            scid(v);
            --v;
            lint tt = st.get(0, 0, n, nm[v], nm[v] + sz[v]);
            int pc = popcount(tt);
            printf("%d\n", pc);
        }
    }

    return 0;
}