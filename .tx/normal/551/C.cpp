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

int main() {
    sciid(n, m);
    rea(a, n);
    while (a[n - 1] == 0) {
        n--;
    }
    lint l = n, r = 1e18;
    while (l + 1 < r) {
        lint mid = (l + r) >> 1;
        int left = m;
        lint curM = 0;
        int i = 0;
        lint curA = a[0];
        while (i < n) {
            lint t = min(curM, curA);
            curM -= t;
            curA -= t;
            if (curA == 0) {
                i++;
                if (i == n) {
                    break;
                }
                curA = a[i];
                curM--;
            }
            if (curM <= 0) {
                curM = mid - i - 1;
                left--;
            }
        }
        if (left >= 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;

    return 0;
}