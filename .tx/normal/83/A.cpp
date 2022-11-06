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

int main() {
    scid(n);
    scid(last);
    lint ans = 1;
    int len = 1;
    for (int i = 1; i < n; i++) {
        scid(x);
        if (x == last) {
            len++;
        } else {
            len = 1;
            last = x;
        }
        ans += len;
    }
    cout << ans;

    return 0;
}