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

typedef long long lint;

using namespace std;

int main() {
    sciiid(n, m, w);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
    }
    int l = *min_element(a.begin(), a.end());
    int r = l + m + 1;
    vector<int> add(n + w);
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        int cm = m;
        int ca = 0;
        add.assign(n + w, 0);
        for (int i = 0; i < n; i++) {
            ca -= add[i];
            if (a[i] + ca < mid) {
                int t = mid - ca - a[i];
                cm -= t;
                if (cm < 0) {
                    break;
                }
                ca += t;
                add[i + w] += t;
            }
        }
        if (cm < 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l;

    return 0;
}