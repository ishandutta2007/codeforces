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

int a[55555];

int main() {
    scid(n);
    lint k = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        k += a[i];
    }
    lint nl = 0, tr = 0;
    lint ans = 0;
    lint v = k / n;
    for (int i = 0; i < n; i++) {
        ans += nl + tr;
        if (a[i] < v) {
            lint t = min(tr, v - a[i]);
            a[i] += t;
            tr -= t;
            nl += v - a[i];
        } else if (a[i] > v) {
            lint t = min(nl, a[i] - v);
            nl -= t;
            a[i] -= t;
            tr += a[i] - v;
        }
    }

    cout << ans;

    return 0;
}