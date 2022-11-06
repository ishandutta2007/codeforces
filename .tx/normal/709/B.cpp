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

int x[111111];

int main() {
    sciid(n, a);
    if (n == 1) {
        cout << 0;
        return 0;
    }
    rea(x, n);
    sort(x, x + n);
    int p = upper_bound(x, x + n, a) - x;
    if (p == n) {
        cout << a - x[1];
        return 0;
    }
    if (p == 0) {
        cout << x[n - 2] - a;
        return 0;
    }
    int ans = 1e9;
    ans = min(ans, a - x[0] + x[n - 2] - x[0]);
    ans = min(ans, x[n - 1] - a + x[n - 1] - x[1]);
    if (p == 1) {
        ans = min(ans, x[n - 1] - a);
    } else {
        ans = min(ans, a - x[1] + x[n - 1] - x[1]);
    }
    if (p == n - 1) {
        ans = min(ans, a - x[0]);
    } else {
        ans = min(ans, x[n - 2] - a + x[n - 2] - x[0]);
    }

    cout << ans;

    return 0;
}