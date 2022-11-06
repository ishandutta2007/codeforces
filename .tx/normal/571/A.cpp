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

int x[3];

int main() {
    sciii(x[0], x[1], x[2]);
    scid(l);
    lint ans = 0;
    for (int tt = 0; tt < 3; tt++) {
        int a = x[0];
        int b = x[1];
        int c = x[2];

        int na = max(0, b + c - a);
        for (int i = na; i <= l; i++) {
            int tbc = min(l - i, a + i - b - c);
            ans += 1LL * (tbc + 1) * (tbc + 2) / 2;
        }

        rotate(x, x + 1, x + 3);
    }

    ans -= 1LL * (l + 1) * (l + 2) * (l + 3) / 6;
    cout << -ans;

    return 0;
}