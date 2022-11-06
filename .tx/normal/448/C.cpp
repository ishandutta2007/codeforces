#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int a[5555];

int ans(int l, int r, int d) {
    if (l >= r) {
        return 0;
    }
    int m = *min_element(a + l, a + r);
    int t = m - d;
    int c = r - l;
    if (c <= t) {
        return c;
    }
    int last = l;
    for (int i = l; i < r; i++) {
        if (a[i] == m) {
            t += ans(last, i, m);
            last = i + 1;
        }
    }
    t += ans(last, r, m);
    return min(c, t);
}

int main() {
    scid(n);
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
    }
    cout << ans(0, n, 0);

    return 0;
}