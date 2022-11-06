#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int a[111111];
int b[111111];
lint sa[111111];
lint sb[111111];

int main() {
    sciid(n, m);
    set<int> all;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        all.insert(a[i]);
    }
    for (int j = 0; j < m; j++) {
        sci(b[j]);
        all.insert(b[j]);
    }
    sort(a, a + n);
    sort(b, b + m);

    for (int i = 0; i < n; i++) {
        sa[i] = a[i];
        if (i) {
            sa[i] += sa[i - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        sb[i] = b[i];
        if (i) {
            sb[i] += sb[i - 1];
        }
    }

    lint ans = 1e18;

    for (int c : all) {
        int i1 = lower_bound(a, a + n, c) - a;
        lint add = 1LL * i1 * c - (i1 > 0 ? sa[i1 - 1] : 0);

        int i2 = upper_bound(b, b + m, c) - b;
        lint sub = i2 == m ? 0 : sb[m - 1] - (i2 > 0 ? sb[i2 - 1] : 0) - 1LL * (m - i2) * c;

        ans = min(ans, add + sub);
    }

    cout << ans;
    return 0;
}