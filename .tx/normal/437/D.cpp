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

int a[111111];
vector<int> g[111111];
int id[111111];

struct Dsu {
    int* a;
    int* sz;

    Dsu(int n) {
        a = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;
            sz[i] = 1;
        }
    }

    int get(int x) {
        return a[x] == x ? x : a[x] = get(a[x]);
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        if (rand() & 1) {
            a[x] = y;
            sz[y] += sz[x];
        } else {
            a[y] = x;
            sz[x] += sz[y];
        }
    }

    int getSz(int x) {
        return sz[get(x)];
    }
};

int main() {
    srand(31);
    sciid(n, m);
    rea(a, n);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        id[i] = i;
    }
    sort(id, id + n, [](int i1, int i2) { return a[i1] > a[i2];});

    double s = 0;

    Dsu dsu(n);

    for (int i = 0; i < n; i++) {
        int v = id[i];
        double t = 0;
        for (int j : g[v]) {
            if (a[j] < a[v]) {
                continue;
            }
            if (dsu.get(v) != dsu.get(j)) {
                t += 2.0 * dsu.getSz(v) * dsu.getSz(j);
                dsu.unite(v, j);
            }
        }
        s += t * a[v];
    }

    printf("%.11f", s / n / (n - 1));
    return 0;
}