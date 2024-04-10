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
    lint d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;

    if (k >= d) {
        cout << a * d;
        return 0;
    }

    lint ans = a * k;
    d -= k;

    if (k * b <= k * a + t) {
        ans += d * b;
        cout << ans;
        return 0;
    }

    lint x = d / k;
    ans += x * (k * a + t);
    d -= k * x;

    ans += min(b * d, t + a * d);

    cout << ans;

    return 0;
}