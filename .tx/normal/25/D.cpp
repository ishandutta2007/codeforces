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

struct Dsu {
    int* a;

    Dsu(int n) {
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
    }

    int get(int x) {
        return a[x] == x ? x : a[x] = get(a[x]);
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (rand() & 1) {
            a[x] = y;
        } else {
            a[y] = x;
        }
    }
};

int main() {
    srand(31);
    scid(n);
    Dsu dsu(n);
    vector<pair<int, int> > del;
    for (int i = 0; i + 1 < n; i++) {
        sciid(x, y);
        --x; --y;
        if (dsu.get(x) == dsu.get(y)) {
            del.push_back({x, y});
        } else {
            dsu.unite(x, y);
        }
    }

    cout << del.size() << "\n";
    for (int i = 0; i < n; i++) {
        if (dsu.get(i) != dsu.get(0)) {
            auto p = del.back();
            del.pop_back();
            printf("%d %d %d %d\n", p.first + 1, p.second + 1, 1, i + 1);
            dsu.unite(i, 0);
        }
    }

    return 0;
}