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

#define pre(a, b) printf("%d %d\n", a, b)

int main() {
    sciiid(n, d, h);
    if (d == 1 && n > 2 || 2 * h < d) {
        cout << -1;
        return 0;
    }
    if (d == 1) {
        cout << "1 2";
        return 0;
    }
    for (int i = 1; i <= h; i++) {
        pre(i, i + 1);
    }
    for (int i = h + 1; i <= d; i++) {
        if (i == h + 1) {
            pre(1, h + 2);
        } else {
            pre(i, i + 1);
        }
    }
    int tc = 1;
    if (h == d) {
        tc = 2;
    }
    for (int i = d + 2; i <= n; i++) {
        pre(tc, i);
    }

    return 0;
}