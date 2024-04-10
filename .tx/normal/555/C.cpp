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

struct Segment {
    int x, y, l, u;

    bool operator<(const Segment& r) const {
        return y < r.y;
    }
};

int main() {
    sciid(n, m);
    set<Segment> s;
    s.insert(Segment{1, n, 1, n});
    while (m-- > 0) {
        int x, y;
        char c;
        scanf("\n%d %d %c", &x, &y, &c);
        auto it = s.lower_bound(Segment{0, x, 0, 0});
        if (it == s.end() || it->x > x) {
            puts("0");
            continue;
        }
        Segment t = *it;
        s.erase(it);
        if (c == 'U') {
            printf("%d\n", t.u - x + 1);
            if (t.x < x) {
                s.insert(Segment{t.x, x - 1, t.l, t.u});
            }
            if (x < t.y) {
                s.insert(Segment{x + 1, t.y, x + 1, t.u});
            }
        } else {
            printf("%d\n", x - t.l + 1);
            if (x > t.x) {
                s.insert(Segment{t.x, x - 1, t.l, x - 1});
            }
            if (x < t.y) {
                s.insert(Segment{x + 1, t.y, t.l, t.u});
            }
        }
    }

    return 0;
}