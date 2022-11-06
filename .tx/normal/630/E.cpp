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

lint f(lint x, lint y) {
    if (x & 1) {
        return (x + 1) / 2 * (y + 1);
    } else {
        return ((x + 2) / 2) * ((y + 2) / 2) + (x / 2) * ((y + 1) / 2);
    }
}

int main() {
    lint x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
//    lint ans = 0;
//    for (lint i = x1; i <= x2; i++) {
//        for (lint j = y1; j <= y2; j++) {
//            if ((i + j) % 2 == 0) {
//                ans++;
//            }
//        }
//    }
//    cerr << ans << endl;
    x1 += 1e9 + 2;
    x2 += 1e9 + 2;
    y1 += 1e9 + 2;
    y2 += 1e9 + 2;
    if ((x1 + y1) & 1) {
        y1++;
        y2++;
    }
//    x1 += 2;
//    x2 += 2;
//    y1 += 2;
//    y2 += 2;

    lint a = f(x2, y2), b = f(x1 - 1, y2), c = f(x2, y1 - 1), d = f(x1 - 1, y1 - 1);
    cout << a - b - c + d;

    return 0;
}