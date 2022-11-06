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

int s[1111];

#define ans(x) cout << fixed << (x); return 0

int main() {
    cout.precision(11);
    sciiid(n, m, h);
    --h;
    rea(s, m);
    int S = 0;
    for (int i = 0; i < m; i++) {
        S += s[i];
    }
    int sh = s[h];
    if (S < n) {
        ans(-1);
    }
    if (S - sh < n - 1) {
        ans(1);
    }
    if (sh == 1) {
        ans(0);
    }
    S--;
    sh--;
    n--;
    double p = 1;
    for (int i = S - sh - n + 1; i <= S - n; i++) {
        p *= i;
    }
    for (int i = S - sh + 1; i <= S; i++) {
        p /= i;
    }
    ans(1 - p);



    return 0;
}