#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    scid(n);
    lint ans = 1e18;
    for (int i = 2; i < (1 << 12); i++) {
        lint x = 0;
        bool st = false;
        int k4 = 0, k7 = 0;
        for (int j = 12; j >= 0; j--) {
            int t = i & (1 << j);
            if (st) {
                x = x * 10 + (t > 0 ? 7 : 4);
                (t > 0 ? k4 : k7)++;
            }
            st |= t > 0;
        }
        if (k4 == k7 && x >= n) {
            ans = min(ans, x);
        }
    }
    cout << ans;

    return 0;
}