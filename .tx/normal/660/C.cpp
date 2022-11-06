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
bool t[333333];

int main() {
    sciid(n, k);
    rea(a, n);
    int ans = 0;
    int ai = 0;
    int i1 = 0, i2 = 0;
    while (i1 < n) {
        i2 = max(i2, i1);
        while (i2 < n && (a[i2] == 1 || k > 0)) {
            if (a[i2] == 0) {
                k--;
                t[i2] = true;
            }
            i2++;
        }
        if (i2 - i1 > ans) {
            ans = i2 - i1;
            ai = i1;
        }
        if (t[i1]) {
            k++;
        }
        i1++;
    }

    cout << ans << "\n";
    for (int i = 0; i < ans; i++) {
        a[ai + i] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }


    return 0;
}