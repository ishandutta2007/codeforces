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

struct mush {
    int a, b, id;
};

mush a[1111];

double f(int a, int b, int t1, int t2, int k) {
    return max(a * t1 * (1 - k / 100.0) + b * t2, b * t1 * (1 - k / 100.0) + a * t2);
}

int main() {
    scid(n);
    sciid(t1, t2);
    scid(k);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = mush{x, y, i};
    }
    sort(a, a + n, [k, t1, t2](const mush& a, const mush& b) {
        double fa = f(a.a, a.b, t1, t2, k);
        double fb = f(b.a, b.b, t1, t2, k);
        return abs(fa - fb) < 1e-9 ? a.id < b.id : fa > fb;
    });
    for (int i = 0; i < n; i++) {
        printf("%d %.2f\n", a[i].id + 1, f(a[i].a, a[i].b, t1, t2, k));
    }


    return 0;
}