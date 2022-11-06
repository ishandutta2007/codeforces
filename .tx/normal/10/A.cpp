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
    sciiid(p1, p2, p3);
    sciid(t1, t2);
    int ans = 0;
    int l0, r0;
    for (int i = 0; i < n; i++) {
        sciid(l1, r1);
        ans += (r1 - l1) * p1;
        if (i) {
            int t = l1 - r0;
            ans += min(t, t1) * p1;
            t = max(0, t - t1);
            ans += min(t, t2) * p2;
            t = max(0, t - t2);
            ans += t * p3;
        }
        l0 = l1;
        r0 = r1;
    }
    cout << ans;
    return 0;
}