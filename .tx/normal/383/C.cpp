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
typedef long double ldouble;

using namespace std;

int a[222222];

vector<int> g[222222];
int tin[222222];
int sz[222222];
int d[222222];
int bck[222222];

int tm = 0;
void dfs(int v, int p, int dd) {
    d[v] = dd;
    tin[v] = tm;
    bck[tm] = v;
    tm++;
    sz[v] = 1;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v, dd + 1);
        sz[v] += sz[i];
    }
}

struct SegmentTree {
    int* a;

    SegmentTree(int n) {
        a = new int[4 * n];
        memset(a, 0, sizeof(int) * 4 * n);
    }

    void add(int i, int l, int r, int ql, int qr, int x) {
        if (l >= qr || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            a[i] += x;
            return;
        }
        int m = (l + r) >> 1;
        add(i * 2 + 1, l, m, ql, qr, x);
        add(i * 2 + 2, m, r, ql, qr, x);
    }


    int get(int i, int l, int r, int q) {
        if (l + 1 == r) {
            return a[i];
        }
        int m = (l + r) >> 1;
        if (q < m) {
            return a[i] + get(i * 2 + 1, l, m, q);
        }
        return a[i] + get(i * 2 + 2, m, r, q);
    }
};

int main() {
    sciid(n, m);
    rea(a, n);
    for (int i = 0; i < n - 1; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    SegmentTree st(n);
    dfs(0, -1, 0);

    while (m-- > 0) {
        scid(t);
        if (t == 1) {
            sciid(x, v);
            --x;
            if (d[x] % 2) {
                v = -v;
            }
            st.add(0, 0, n, tin[x], tin[x] + sz[x], v);
        } else {
            scid(x);
            --x;
            int v = st.get(0, 0, n, tin[x]);
            if (d[x] % 2) {
                v = -v;
            }
            cout << v + a[x] << "\n";
        }
    }


    return 0;
}