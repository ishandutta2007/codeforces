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

int a[111111];
int c[111111];

int main() {
    sciid(n, k);
    int x = 0;
    for (int i = 0; i < n; i++) {
        scid(t);
        --t;
        if (x == 0 || t != a[x - 1]) {
            a[x++] = t;
        }
    }
    n = x;
    for (int i = 0; i < n; i++) {
        int t = 0;
        if (i > 0 && a[i] != a[i - 1]) {
            t++;
        }
        if (i + 1 < n && a[i] != a[i + 1]) {
            t++;
        }
        if (i > 0 && i + 1 < n && a[i - 1] != a[i + 1]) {
            t--;
        }
        c[a[i]] += t;
    }

    int mx = 0;
    for (int i = 1; i < k; i++) {
        if (c[i] > c[mx]) {
            mx = i;
        }
    }
    cout << mx + 1;

    return 0;
}