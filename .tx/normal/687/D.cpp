#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
typedef long double ldouble;

using namespace std;

struct Edge {
    int f, t, w, id;

    bool operator<(const Edge& r) const {
        return w < r.w;
    }
};

Edge es[1111111];

int dsu[1111];
int dr[1111];

int pl[1111];
int pr[1111];

void init(int n) {
    for (int i = 0; i < n; i++) {
        dsu[i] = i;
        dr[i] = 0;
        pl[i] = i;
        pr[i] = -1;
    }
}

int get(int x) {
    return dsu[x] == x ? x : dsu[x] = get(dsu[x]);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
        return;
    }
    if (dr[x] < dr[y]) {
        dsu[x] = y;
    } else {
        dsu[y] = x;
        if (dr[x] == dr[y]) {
            dr[x]++;
        }
    }
}



int main() {
    init_cin
    sciiid(n, m, q);
    for (int i = 0; i < m; i++) {
        sciiid(x, y, z);
        --x; --y;
        es[i] = Edge{x, y, z, i};
    }

    sort(es, es + m);

    while (q-- > 0) {
        init(n);
        for (int i = 0; i < n; i++) {
            pl[i] = i;
            pr[i] = -1;
        }

        sciid(l, r);
        --l; --r;
        int res = -1;
        for (int i = m - 1; i >= 0; i--) {
            Edge& e = es[i];
            if (e.id < l || e.id > r) {
                continue;
            }
            int xx = get(e.f);
            int yy = get(e.t);
            if (xx == yy) {
                res = e.w;
                break;
            }
            if (pr[xx] != -1) {
                unite(pr[xx], yy);
            }

            if (pr[yy] != -1) {
                unite(pr[yy], xx);
            }

            pr[xx] = yy;
            pr[yy] = xx;
        }

        printf("%d\n", res);
    }



    return 0;
}