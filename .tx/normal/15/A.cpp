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

pair<int, int> a[1111];

int main() {
    sciid(n, t);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = {x * 2, y};
    }
    sort(a, a + n);
    int ans = 2;
    for (int i = 0; i + 1 < n; i++) {
        int d = a[i + 1].first - a[i].first - a[i + 1].second - a[i].second;
        if (d == 2 * t) {
            ans++;
        } else if (d > 2 * t) {
            ans += 2;
        }
    }
    cout << ans;

    return 0;
}