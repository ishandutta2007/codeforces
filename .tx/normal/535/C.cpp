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
    sciiid(a, b, n);
    while (n-- > 0) {
        sciiid(l, t, m);
        lint ta = a + 1LL * (l - 1) * b;
        if (t < ta) {
            puts("-1");
            continue;
        }
        int r = 1e6 + 1;
        int ol = l;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            lint k = mid - ol;
            lint s = ta * (k + 1) + b * k * (k + 1) / 2;
            if (s <= t * min((lint) m, k + 1) && ta + k * b <= t) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%d\n", l);
    }


    return 0;
}