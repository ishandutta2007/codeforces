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
    sciid(n, x);
    --x;
    rea(a, n);
    int mn = *min_element(a, a + n);
    lint s = 0;
    if (mn > 1) {
        s = 1LL * n * (mn - 1);
        for (int i = 0; i < n; i++) {
            a[i] -= mn - 1;
        }
    }
    while (a[x] != 0) {
        a[x]--;
        s++;
        x = (x - 1 + n) % n;
    }

    for (int i = 0; i < n; i++) {
        if (i == x) {
            cout << s;
        } else {
            cout << a[i];
        }
        cout << " ";
    }

    return 0;
}