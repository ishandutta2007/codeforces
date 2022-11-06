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

int t[111];

int main() {
    sciiid(n, a, b);
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (a == n - 1) {
        cout << -1;
        return 0;
    }
    t[0] = 1;
    if (b == 0) {
        t[1] = 1;
    }
    for (int i = b == 0 ? 1 : 0; i + 1 < n; i++) {
        if (b > 0) {
            t[i + 1] = 2 * t[i];
            b--;
        } else if (a > 0) {
            t[i + 1] = t[i] + 1;
            a--;
        } else {
            t[i + 1] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << t[i] << " ";
    }

    return 0;
}