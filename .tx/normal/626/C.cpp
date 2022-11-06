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
    sciid(n, m);
    int ans = 1e9;
    for (int i = 3 * m; i <= 1e7; i += 3) {
        if (min(i / 2, i / 2 - i / 6 + i / 3 - m) >= n) {
            ans = min(ans, i);
            break;
        }
    }
    for (int i = 2 * n; i <= 1e7; i += 2) {
        if (min(i / 3, i / 3 - i / 6 + i / 2 - n) >= m) {
            ans = min(ans, i);
            break;
        }
    }
    cout << ans;
    return 0;
}