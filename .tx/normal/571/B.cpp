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

int a[333333];
lint d[5555][5555];

int main() {
    sciid(n, k);
    rea(a, n);
    sort(a, a + n);
    int cl = n % k;
    if (cl == 0) {
        cl = k;
    }
    int cs = k - cl;

    int ll = (n + k - 1) / k;
    int ls = ll - 1;

    for (int i = 0; i < 5555; i++) {
        for (int j = 0; j < 5555; j++) {
            d[i][j] = 1e18;
        }
    }
    d[0][0] = 0;

    for (int i = 0; i <= cl; i++) {
        for (int j = 0; j <= cs; j++) {
            int nt = i * ll + j * ls;
            if (i < cl) {
                d[i + 1][j] = min(d[i + 1][j], d[i][j] + a[nt + ll - 1] - a[nt]);
            }
            if (j < cs) {
                d[i][j + 1] = min(d[i][j + 1], d[i][j] + a[nt + ls - 1] - a[nt]);
            }
        }
    }

    cout << d[cl][cs];

    return 0;
}