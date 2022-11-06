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

int main() {
    sciid(k, b);
    sciid(n, t);
    if (k == 1) {
        if (t >= 1 + 1LL * n * b) {
            cout << 0;
        } else {
            cout << (1 + 1LL * n * b - t + b - 1) / b;
        }
        return 0;
    }
    lint kk = 1;
    for (int i = 0; i <= n; i++) {
        if (kk * (k - 1 + b) > 1LL * t * (k - 1) + b) {
            cout << n - i + 1;
            return 0;
        }
        kk *= k;
    }

    cout << 0;
    return 0;
}