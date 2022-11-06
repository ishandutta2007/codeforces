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

int x[11], y[11];

int main() {
    scid(n);
    lint s = 0;
    for (int i = 0; i < n; i++) {
        sciid(a, c);
        sciid(b, d);
        s += (b - a) * (d - c);
        x[i * 2] = a;
        x[i * 2 + 1] = b;
        y[i * 2] = c;
        y[i * 2 + 1] = d;
    }

    int mnx = *min_element(x, x + 2 * n);
    int mxx = *max_element(x, x + 2 * n);
    int mny = *min_element(y, y + 2 * n);
    int mxy = *max_element(y, y + 2 * n);

    int a = mxx - mnx;
    int b = mxy - mny;
    if (a != b || 1LL * a * b != s) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}