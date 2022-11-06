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

int a[11111];

int main() {
    sciid(n, k);
    rea(a, n);
    double l = 0, r = 1000;
    for (int sc = 0; sc < 200; sc++) {
        double m = (l + r) / 2;
        double ov = 0;
        double ls = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > m) {
                ov += a[i] - m;
            } else {
                ls += m - a[i];
            }
        }
        ov *= (1 - k / 100.0);
        if (ov > ls - 1e-9) {
            l = m;
        } else {
            r = m;
        }
    }

    printf("%.11f", l);


    return 0;
}