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
    sciid(n, m);
    sciid(a, b);
    --a;
    --b;
    if (a / m == b / m) {
        cout << 1;
    } else {
        int ra = m - a % m;
        int lb = b % m + 1;
        int cb = (b - a + 1 - ra - lb) / m;
        if (cb != 0) {
            if (ra + lb == m) {
                cout << 2;
                return 0;
            }
            int ans = 1;
            if (a % m != 0) {
                ans++;
            }
            if (b % m != m - 1 && b != n - 1) {
                ans++;
            }
            cout << ans;
        } else {
            if (a % m == 0 && (b % m == m - 1 || b == n - 1)) {
                cout << 1;
            } else {
                cout << 2;
            }
        }
    }

    return 0;
}