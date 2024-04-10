#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int main() {
    sciiid(x, y, z);
    sciiid(x1, y1, z1);
    int a[6];
    for (int i = 0; i < 6; i++) {
        sci(a[i]);
    }
    int ans = 0;
    if (y < 0) {
        ans += a[0];
    }
    if (y > y1) {
        ans += a[1];
    }
    if (z < 0) {
        ans += a[2];
    }
    if (z > z1) {
        ans += a[3];
    }
    if (x < 0) {
        ans += a[4];
    }
    if (x > x1) {
        ans += a[5];
    }

    cout << ans;
    return 0;
}