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

struct pt {
    int x, y, id;
};

pt a[111111];

int cross(const pt& a, const pt& b) {
    return a.x * b.y - b.x * a.y;
}

int dot(const pt& a, const pt& b) {
    return a.x * b.x + a.y * b.y;
}

double len(const pt& a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

bool cmp(const pt& a, const pt& b) {
    if (a.y >= 0 != b.y >= 0) {
        return a.y > b.y;
    }
    if (a.y == 0 && b.y == 0) {
        return a.x > b.x;
    }
    return cross(a, b) > 0;
}

const long double PI = acosl(-1.0);

long double ang(const pt& a, const pt& b) {
    long double res = abs(atan2l(a.y, a.x) - atan2l(b.y, b.x));
    if (res > PI) {
        res = 2 * PI - res;
    }
    return res;
}

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = pt{x, y, i};
    }
    sort(a, a + n, cmp);
//    for (int i = 0; i < n; i++) {
//        cout << a[i].x << " " << a[i].y << "\n";
//    }
    a[n] = a[0];
    long double minAng = 1e9;
    int a1 = -1, a2 = -1;
    for (int i = 0; i < n; i++) {
        long double an = ang(a[i], a[i + 1]);
        if (an < minAng) {
            minAng = an;
            a1 = a[i].id;
            a2 = a[i + 1].id;
        }
    }
    cout << a1 + 1 << " " << a2 + 1;


    return 0;
}