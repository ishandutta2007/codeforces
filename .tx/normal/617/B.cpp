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

int a[111];

int main() {
    scid(n);
    int f1 = -1;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (f1 == -1 && a[i] == 1) {
            f1 = i;
        }
    }
    if (f1 == -1) {
        cout << 0;
        return 0;
    }

    lint ans = 1;
    for (int i = f1 + 1; i < n; i++) {
        if (a[i] == 1) {
            ans *= (i - f1);
            f1 = i;
        }
    }
    cout << ans;
    return 0;
}