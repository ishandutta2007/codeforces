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

int a[111];

bool g[111][111];

int main() {
    sciid(n, m);
    rea(a, n);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x;
        --y;
        g[x][y] = g[y][x] = true;
    }
    int ans = 1e9;
    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = 0; i2 < n; i2++) {
            for (int i3 = 0; i3 < n; i3++) {
                if (g[i1][i2] && g[i1][i3] && g[i2][i3]) {
                    ans = min(ans, a[i1] + a[i2] + a[i3]);
                }
            }
        }
    }

    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}