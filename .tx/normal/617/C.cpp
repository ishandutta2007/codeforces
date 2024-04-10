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

pair<int, int> p[2222];

lint sqdist(lint x1, lint y1, lint x2, lint y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    scid(n);
    sciid(x1, y1);
    sciid(x2, y2);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        p[i] = {x, y};
    }
    sort(p, p + n, [x1, y1](const pair<int, int>& p1, const pair<int, int>& p2) {
        lint d1 = sqdist(x1, y1, p1.first, p1.second);
        lint d2 = sqdist(x1, y1, p2.first, p2.second);
        return d1 < d2;
    });
    lint ans = 1e18;
    for (int i = 0; i <= n; i++) {
        lint m1 = 0;
        for (int j = 0; j < i; j++) {
            m1 = max(m1, sqdist(x1, y1, p[j].first, p[j].second));
        }
        lint m2 = 0;
        for (int j = i; j < n; j++) {
            m2 = max(m2, sqdist(x2, y2, p[j].first, p[j].second));
        }
        ans = min(ans, m1 + m2);
    }
    cout << ans;


    return 0;
}