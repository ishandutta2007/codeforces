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

int main() {
    scid(n);
    int kInt = 0;
    int s = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        scanf("%d.%d", &x, &y);
        s -= y;
        if (y == 0) {
            kInt++;
        }
    }
    int ans = 1e9;
    for (int i = max(0, n - kInt); i <= min(n, 2 * n - kInt); i++) {
        ans = min(ans, abs(s + i * 1000));
    }
    printf("%d.%03d", ans / 1000, ans % 1000);

    return 0;
}