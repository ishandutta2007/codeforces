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

int c[111];

int main() {
    sciid(n, k);
    for (int i = 0; i < n; i++) {
        scid(x);
        c[x]++;
    }
    int ans = 0;
    while (true) {
        bool any = false;
        for (int i = k - 1; i >= 1; i--) {
            if (c[i] != 0) {
                any = true;
                c[i]--;
                c[i + 1]++;
            }
        }
        if (!any) {
            break;
        }
        ans++;
    }
    cout << ans;

    return 0;
}