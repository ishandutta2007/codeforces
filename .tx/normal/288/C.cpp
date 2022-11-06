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

int ans[1111111];

int mx2(int x) {
    int res = 1;
    while (res <= x) {
        res *= 2;
    }
    return res;
}

bool used[1111111];

int main() {
    scid(n);
    lint sm = 0;
    for (int i = n; i >= 0; i--) {
        if (used[i]) {
            continue;
        }
        int x = mx2(i);
        int y = i ^ (x - 1);
        ans[y] = i;
        ans[i] = y;
        sm += 2 * (i ^ y);
        used[i] = used[y] = true;
    }
    cout << sm << "\n";
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}