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

int mn[1111];

int main() {
    sciiid(n, m, k);
    for (int i = 0; i < m; i++) {
        mn[i] = 1e9;
    }
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        --x;
        mn[x] = min(mn[x], y);
    }

    int s = 0;
    for (int i = 0; i < m; i++) {
        s += mn[i];
    }

    cout << min(s, k);

    return 0;
}