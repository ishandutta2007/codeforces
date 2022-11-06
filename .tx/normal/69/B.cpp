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

int mn[111];
int wc[111];

int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        mn[i] = 1e9;
    }
    for (int i = 0; i < m; i++) {
        sciid(l, r);
        --l; --r;
        sciid(t, c);
        for (int j = l; j <= r; j++) {
            if (t < mn[j]) {
                mn[j] = t;
                wc[j] = c;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += wc[i];
    }
    cout << ans;

    return 0;
}