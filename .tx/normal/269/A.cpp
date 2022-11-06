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
    scid(n);
    vector< pair<int, int> > a;
    for (int i = 0; i < n; ++i) {
        sciid(x, y);
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i + 1 < n; i++) {
        int k1 = a[i].first;
        int a1 = a[i].second;
        int k2 = a[i + 1].first;
        int a2 = a[i + 1].second;
        if (k2 - k1 >= 16) {
            continue;
        }
        int t = 1 << (2 * (k2 - k1));
        a[i + 1].second += max(0, (a1 + t - 1) / t - a2);
    }
    int ans = a[n - 1].first;
    while (a[n - 1].second > 1) {
        a[n - 1].second = (a[n - 1].second + 3) / 4;
        ans++;
    }
    cout << max(ans, a[n - 1].first + 1);
    return 0;
}