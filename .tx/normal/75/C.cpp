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
    sciid(a, b);
    vector<int> ds;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (b % i == 0) {
                ds.push_back(i);
            }
            if (i * i != a && b % (a / i) == 0) {
                ds.push_back(a / i);
            }
        }
    }
    scid(n);
    while (n-- > 0) {
        sciid(l, r);
        int ans = -1;
        for (int i : ds) {
            if (l <= i && i <= r) {
                ans = max(ans, i);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}