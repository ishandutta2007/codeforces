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

pair<int, int> a[111111];

int ans[111111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i] = {x, i};
    }
    sort(a, a + n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        if (mx < a[i].second) {
            ans[a[i].second] = -1;
        } else {
            ans[a[i].second] = mx - a[i].second - 1;
        }
        mx = max(mx, a[i].second);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}