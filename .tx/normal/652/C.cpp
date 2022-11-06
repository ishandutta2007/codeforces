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

int a[333333];
pair<int, int> ps[333333];

int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        scid(x);
        --x;
        a[x] = i;
    }
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        x = a[x];
        y = a[y];
        if (x > y) {
            swap(x, y);
        }
        ps[i] = {y, x};
    }
    sort(ps, ps + m);
    int mx = -1;
    int c = 0;
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        while (c < m && ps[c].first == i) {
            mx = max(mx, ps[c].second);
            c++;
        }
        ans += i - mx;
    }
    cout << ans;

    return 0;
}