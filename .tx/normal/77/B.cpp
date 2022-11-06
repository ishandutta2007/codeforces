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

int main() {
    init_cin
    int t;
    cin >> t;
    while (t-- > 0) {
        int p, q;
        cin >> p >> q;
        if (q == 0) {
            printf("%.11f\n", 1.0);
            continue;
        }
        if (p == 0) {
            printf("%.11f\n", 0.5);
            continue;
        }
        double a = p;
        double b = q;
        b *= 4;

        double sq;
        if (b > a) {
            sq = a * a / 2;
        } else {
            sq = (2 * a - b) / 2 * b;
        }
        double ans = sq / (a * b * 2) + 0.5;
        printf("%.11f\n", ans);
    }

    return 0;
}