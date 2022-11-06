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

int a[111111];
int b[111111];

int main() {
    sciid(n, k);
    rea(a, n);
    rea(b, n);
    lint l = 0, r = 2e9 + 1;
    while (r - l > 1) {
        lint m = (l + r) >> 1;
        lint nk = 0;
        for (int i = 0; nk <= k && i < n; i++) {
            lint d = max(0LL, 1LL * a[i] * m - b[i]);
            nk += d;
        }
        if (nk > k) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l;

    return 0;
}