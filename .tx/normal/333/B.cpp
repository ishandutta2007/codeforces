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

bool a[1111][1111];

bool canr[1111];
bool canc[1111];

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        a[--x][--y] = true;
    }
    for (int i = 1; i + 1 < n; i++) {
        canr[i] = true;
        canc[i] = true;
        for (int j = 0; j < n; j++) {
            canr[i] &= !a[i][j];
            canc[i] &= !a[j][i];
        }
    }
    if (n % 2 == 1) {
        if (canc[n / 2]) {
            canr[n / 2] = false;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (canc[i]) {
            res++;
        }
        if (canr[i]) {
            res++;
        }
    }
    cout << res;

    return 0;
}