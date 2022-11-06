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

int mn[1111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
    }
    scid(m);
    memset(mn, -1, sizeof(mn));
    for (int i = 0; i < m; i++) {
        sciiid(f, t, c);
        --f; --t;
        if (mn[t] == -1 || mn[t] > c) {
            mn[t] = c;
        }
    }
    int c1 = 0;
    for (int i = 0; i < n; i++) {
        if (mn[i] == -1) {
            c1++;
        }
    }
    if (c1 > 1) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mn[i] != -1) {
            ans += mn[i];
        }
    }
    cout << ans;



    return 0;
}