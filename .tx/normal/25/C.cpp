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

int d[333][333];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sci(d[i][j]);
        }
    }
    scid(k);
    while (k-- > 0) {
        sciiid(x, y, z);
        --x; --y;
        d[x][y] = d[y][x] = min(d[x][y], z);
        lint s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][x] + d[x][y] + d[y][j]);
                d[i][j] = min(d[i][j], d[i][y] + d[y][x] + d[x][j]);
                d[j][i] = d[i][j];
                s += d[i][j];
            }
        }
        cout << s << " ";
    }

    return 0;
}