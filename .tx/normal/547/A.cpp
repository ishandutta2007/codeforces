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

int u1[1111111];
int u2[1111111];

int main() {
    scid(m);
    sciid(h1, a1);
    sciid(x1, y1);
    sciid(h2, a2);
    sciid(x2, y2);

    int oh1 = h1, oh2 = h2;

    int l1 = -1, p1 = -1;
    memset(u1, -1, sizeof(u1));
    memset(u2, -1, sizeof(u2));
    u1[h1] = 0;
    bool ic1, ic2;
    for (int i = 1; i <= m; i++) {
        h1 = (1LL * x1 * h1 + y1) % m;
        if (u1[h1] != -1) {
            p1 = i - u1[h1];
            ic1 = u1[h1] <= l1;
            break;
        }
        if (h1 == a1) {
            l1 = i;
        }
        u1[h1] = i;
    }
    if (l1 == -1) {
        cout << -1;
        return 0;
    }

    int l2 = -1, p2 = -1;
    u2[h2] = 0;
    for (int i = 1; i <= m; i++) {
        h2 = (1LL * x2 * h2 + y2) % m;
        if (u2[h2] != -1) {
            p2 = i - u2[h2];
            ic2 = u2[h2] <= l2;
            break;
        }
        if (h2 == a2) {
            l2 = i;
        }
        u2[h2] = i;
    }
    if (l2 == -1) {
        cout << -1;
        return 0;
    }

    if (!ic1 && !ic2) {
        if (l1 == l2) {
            cout << l1;
        } else {
            cout << -1;
        }
        return 0;
    }

    if (!ic1) {
        if (l1 < l2 || (l1 - l2) % p2 != 0) {
            cout << -1;
        } else {
            cout << l1;
        }
        return 0;
    }
    if (!ic2) {
        if (l2 < l1 || (l2 - l1) % p2 != 0) {
            cout << -1;
        } else {
            cout << l2;
        }
        return 0;
    }

    for (int i = 0; i <= m; i++) {
        lint x = 1LL * p2 * i + l2 - l1;
        if (x >= 0 && x % p1 == 0) {
            cout << l2 + 1LL * p2 * i;
            return 0;
        }
    }
    cout << -1;


    return 0;
}