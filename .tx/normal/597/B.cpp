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

struct Elem {
    int l, r;

    bool operator<(const Elem& r) const {
        return l == r.l ? this->r > r.r : l < r.l;
    }
};

Elem a[555555];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = Elem{x, y};
    }
    sort(a, a + n);
    int cr = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].l > cr) {
            ans++;
            cr = a[i].r;
        } else {
            cr = min(cr, a[i].r);
        }
    }
    cout << ans;

    return 0;
}