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
    sciid(x, y);
    if (x == 0 || y == 0) {
        cout << "black";
        return 0;
    }

    int r2 = x * x + y * y;
    int r = floor(sqrt(r2));
    if (r * r == r2) {
        cout << "black";
        return 0;
    }


    if (x < 0) {
        x *= -1;
        y *= -1;
    }

    if (y > 0 && r % 2 == 0 || y < 0 && r % 2 == 1) {
        cout << "black";
    } else {
        cout << "white";
    }


    return 0;
}