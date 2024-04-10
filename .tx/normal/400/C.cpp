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

int main() {
    sciid(n, m);
    sciiid(x, y, z);
    x %= 4;
    y %= 2;
    z %= 4;
    scid(p);
    int on = n, om = m;
    for (; p-- > 0; ) {
        sciid(a, b);
        for (int i = 0; i < x; i++) {
            int na = b;
            int nb = n - a + 1;
            a = na;
            b = nb;
            swap(n, m);
        }
        for (int i = 0; i < y; i++) {
            b = m + 1 - b;
        }
        for (int i = 0; i < z; i++) {
            int na = m + 1 - b;
            int nb = a;
            a = na;
            b = nb;
            swap(n, m);
        }
        printf("%d %d\n", a, b);
        n = on;
        m = om;
    }

    return 0;
}