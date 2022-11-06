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
typedef long double ldouble;

using namespace std;

int main() {
    lint s, x;
    cin >> s >> x;
    int c1 = 0;
    lint ms = 0;
    bool wt = false;
    for (int i = 60; i >= 0; i--) {
        if (x & (1LL << i)) {
            c1++;
            ms += 1LL << i;
        } else {
            if (ms + (2LL << i) <= s) {
                ms += 2LL << i;
                wt = true;
            }
        }
    }
    if (ms != s) {
        cout << 0;
        return 0;
    }
    if (wt) {
        cout << (1LL << c1);
    } else {
        cout << ((1LL << c1) - 2);
    }


    return 0;
}