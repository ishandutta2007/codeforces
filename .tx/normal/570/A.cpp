#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int a[111];

int main() {
    sciid(m, n);
    int am = -1;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int km = -1;
        int pm = -1;
        for (int j = 0; j < m; j++) {
            scid(x);
            if (x > km) {
                km = x;
                pm = j;
            }
        }
        a[pm]++;
        if (a[pm] > am || (a[pm] == am && pm < ans)) {
            am = a[pm];
            ans = pm;
        }
    }
    cout << ans + 1;
    return 0;
}