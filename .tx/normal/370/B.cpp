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

pair<lint, lint> a[111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(m);
        for (int j = 0; j < m; j++) {
            scid(x);
            --x;
            if (x < 50) {
                a[i].first |= 1LL << x;
            } else {
                a[i].second |= 1LL << (x - 50);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bool can = true;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if ((a[i].first & a[j].first) == a[j].first && (a[i].second & a[j].second) == a[j].second) {
                can = false;
                break;
            }
        }
        puts(can ? "YES" : "NO");
    }

    return 0;
}