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
#include <bitset>

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

int n, M;
int a[111111];
vector<int> g[111111];
int tin[111111];
int sz[111111];

int tm = 0;
int bnn[111111];

void dfs(int v, int p) {
    tin[v] = tm;
    bnn[tm] = v;
    tm++;
    sz[v] = 1;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        sz[v] += sz[i];
    }
}

struct SegmentTree {
    vector<bitset<1000> > t;
    vector<int> aa;

    SegmentTree() {
        t.resize(4 * n);
        aa.resize(4 * n);
        build(0, 0, n);
    }

    void build(int i, int l, int r) {
        if (l + 1 == r) {
            t[i].set(a[bnn[l]] % M);
            return;
        }
        int m = (l + r) >> 1;
        build(i * 2 + 1, l, m);
        build(i * 2 + 2, m, r);
        t[i] = t[i * 2 + 1] | t[i * 2 + 2];
    }

    void push(int i, int l, int r) {
        t[i] = (t[i] << aa[i]) | (t[i] >> (M - aa[i]));
        if (l + 1 != r) {
            aa[i * 2 + 1] = (aa[i * 2 + 1] + aa[i]) % M;
            aa[i * 2 + 2] = (aa[i * 2 + 2] + aa[i]) % M;
        }
        aa[i] = 0;
    }

    void add(int i, int l, int r, int ql, int qr, int x) {
        push(i, l, r);
        if (l >= qr || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            aa[i] = (aa[i] + x) % M;
            push(i, l, r);
            return;
        }
        int m = (l + r) >> 1;
        add(i * 2 + 1, l, m, ql, qr, x);
        add(i * 2 + 2, m, r, ql, qr, x);
        t[i] = t[i * 2 + 1] | t[i * 2 + 2];
    }

    bitset<1000> get(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (l >= qr || r <= ql) {
            return bitset<1000>(0);
        }
        if (ql <= l && r <= qr) {
            return t[i];
        }
        int m = (l + r) >> 1;
        return get(i * 2 + 1, l, m, ql, qr) | get(i * 2 + 2, m, r, ql, qr);
    }
};

bool isPrime(int x) {
    bool res = x != 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = false;
            break;
        }
    }
    return res;
}

int main() {
    scii(n, M);
    rea(a, n);
    for (int i = 1; i < n; i++) {
        sciid(x, y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bitset<1000> prs;
    for (int i = 2; i < M; i++) {
        if (isPrime(i)) {
            prs.set(i);
        }
    }
    dfs(0, -1);
    SegmentTree st;
    scid(q);
    while (q-- > 0) {
        scid(t);
        if (t == 1) {
            sciid(v, x);
            v--;
            st.add(0, 0, n, tin[v], tin[v] + sz[v], x);
        } else {
            scid(v);
            v--;
            bitset<1000> r = st.get(0, 0, n, tin[v], tin[v] + sz[v]);
//            cerr << r << endl;
            cout << (r & prs).count() << "\n";
//            return 0;
        }
    }

    return 0;
}