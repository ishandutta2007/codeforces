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

pair<pair<int, int>, int> a[111111];

lint sqdist(const pair<int, int> &a, const pair<int, int> &b) {
    return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);
}

lint vec(lint x1, lint y1, lint x2, lint y2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = {{x, y}, i + 1};
    }

    auto t = a[0];

    sort(a, a + n, [t](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
        return sqdist(a.first, t.first) < sqdist(b.first, t.first);
    });

    for (int i = 2; i < n; i++) {
        if (vec(a[i].first.first - a[0].first.first, a[i].first.second - a[0].first.second, a[1].first.first - a[0].first.first, a[1].first.second - a[0].first.second) != 0) {
            printf("%d %d %d", a[0].second, a[1].second, a[i].second);
            return 0;
        }
    }


    return 0;
}