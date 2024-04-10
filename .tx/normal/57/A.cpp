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

int n;

void rot(int& x, int& y) {
    int nx = y;
    int ny = n - x;
    x = nx;
    y = ny;
}

int main() {
    sci(n);
    sciid(x1, y1);
    sciid(x2, y2);
    while (x1 != 0) {
        rot(x1, y1);
        rot(x2, y2);
    }
    int ans;
    if (x2 == 0) {
        ans = abs(y1 - y2);
    } else if (x2 == n) {
        ans = y1 + y2 + n;
    } else if (y2 == 0) {
        ans = y1 + x2;
    } else {
        ans = n - y1 + x2;
    }
    ans = min(ans, 4 * n - ans);
    cout << ans;

    return 0;
}