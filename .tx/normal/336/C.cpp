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

int a[111111];

int f(int x) {
    if (x == 0) {
        return -1;
    }
    int res = 0;
    while ((x & 1) == 0) {
        res++;
        x >>= 1;
    }
    return res;
}

int main() {
    scid(n);
    rea(a, n);
    int ans = -1;
    int ai = -1;
    int ahit = -1;
    for (int i = 29; i >= 0; i--) {
        int cur = (1 << 30) - 1;
        int chit = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] & (1 << i)) {
                cur &= a[j];
                chit++;
            }
        }
        cur = f(cur);
        if (chit != 0 && (cur > ans || cur == ans && chit > ahit)) {
            ans = cur;
            ai = i;
            ahit = chit;
        }
    }
    vector<int> aa;
    for (int i = 0; i < n; i++) {
        if (a[i] & (1 << ai)) {
            aa.push_back(a[i]);
        }
    }
    cout << aa.size() << "\n";
    for (auto i : aa) {
        cout << i << " ";
    }

    return 0;
}