#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

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

struct pile {
    int mid, l, r;

    bool operator<(const pile& r) const {
        return mid > r.mid;
    }
};

pile a[111];

int main() {
    scid(n);

    for (int i = 0; i < n; i++) {
        scid(x);
        int l = 0;
        for (int j = 0; j < x / 2; j++) {
            scid(y);
            l += y;
        }
        int mid = 0;
        if (x % 2 == 1) {
            sci(mid);
        }
        int r = 0;
        for (int j = 0; j < x / 2; j++) {
            scid(y);
            r += y;
        }
        a[i] = pile{mid, l, r};
    }
    sort(a, a + n);
    int al = 0;
    int ar = 0;
    for (int i = 0; i < n; i++) {
        al += a[i].l;
        ar += a[i].r;
        if (i & 1) {
            ar += a[i].mid;
        } else {
            al += a[i].mid;
        }
    }
    cout << al << " " << ar;

    return 0;
}