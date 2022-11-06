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

int n, m;

struct elem {
    int x, y, v;
    int id;

    elem() {}

    elem(int x, int y, int v) : x(x), y(y), v(v) {
        id = x * m + y;
    }

    bool operator<(const elem& r) const {
        return v < r.v;
    }
};

struct Dsu {
    int* a;
    int* r;

    Dsu(int n) {
        a = new int[n];
        r = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;
            r[i] = 0;
        }
    }

    int get(int x) {
        return x == a[x] ? x : a[x] = get(a[x]);
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        if (r[x] < r[y]) {
            a[x] = y;
        } else {
            a[y] = x;
            if (r[x] == r[y]) {
                r[x]++;
            }
        }
    }
};

elem a[1111111];
int mxr[1111111];
int mxc[1111111];
int ans[1111111];

int byr[1111111];
int byc[1111111];

int tmx[1111111];

int main() {
    scii(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scid(x);
            a[i * m + j] = elem(i, j, x);
        }
    }
    int all = n * m;
    sort(a, a + all);
    Dsu dsu(all);

    memset(byr, -1, sizeof(byr));
    memset(byc, -1, sizeof(byc));

    int i = 0;
    while (i < all) {
        int j = i;
        int mx = 0;
        while (j < all && a[j].v == a[i].v) {
            int cr = a[j].x;
            int cc = a[j].y;
            int cid = a[j].id;
            if (byr[cr] != -1) {
                dsu.unite(cid, byr[cr]);
            }
            byr[cr] = cid;
            if (byc[cc] != -1) {
                dsu.unite(cid, byc[cc]);
            }
            byc[cc] = cid;
            j++;
        }

        for (int k = i; k < j; k++) {
            int dn = dsu.get(a[k].id);
            int cmx = max(mxr[a[k].x], mxc[a[k].y]);
            tmx[dn] = max(tmx[dn], cmx + 1);
        }

        for (int k = i; k < j; k++) {
            int cmx = tmx[dsu.get(a[k].id)];
            ans[a[k].x * m + a[k].y] = cmx;
            mxr[a[k].x] = cmx;
            mxc[a[k].y] = cmx;

            byr[a[k].x] = -1;
            byc[a[k].y] = -1;
        }
        i = j;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", ans[i * m + j]);
        }
        printf("\n");
    }

    return 0;
}