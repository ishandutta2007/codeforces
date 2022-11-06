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

int main() {
    scid(n);
    map<pair<int, int>, int> m;
    map<int, int> by, bx;
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        bx[x]++;
        by[y]++;
        m[{x, y}]++;
    }
    lint ans = 0;
    for (auto& it : bx) {
        ans += 1LL * it.second * (it.second - 1) / 2;
    }
    for (auto& it : by) {
        ans += 1LL * it.second * (it.second - 1) / 2;
    }
    for (auto& it : m) {
        ans -= 1LL * it.second * (it.second - 1) / 2;
    }
    cout << ans;

    return 0;
}