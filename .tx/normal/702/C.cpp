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

int a[111111];
int b[111111];

int main() {
    sciid(n, m);
    int ans = -1;
    rea(a, n);
    rea(b, m);
    sort(a, a + n);
    sort(b, b + m);
    int ib = 0;
    for (int i = 0; i < n; i++) {
        while (ib < m && a[i] >= b[ib]) {
            ib++;
        }
        int d = 2e9;
        if (ib < m) {
            d = min(d, abs(b[ib] - a[i]));
        }
        if (ib > 0) {
            d = min(d, abs(b[ib - 1] - a[i]));
        }
        ans = max(ans, d);
    }

    cout << ans;


    return 0;
}