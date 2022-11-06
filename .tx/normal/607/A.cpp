#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int d[111111];

int main() {
    scid(n);
    vector<pair<int, int> > a;
    for (int i = 0; i < n; ++i) {
        sciid(x, y);
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        int x = a[i].first - a[i].second;
        int r = i;
        int l = -1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (a[m].first < x) {
                l = m;
            } else {
                r = m;
            }
        }
        d[i] = i - r;
        if (r > 0) {
            d[i] += d[r - 1];
        }
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        ans = min(ans, d[i] + n - i - 1);
    }
    cout << ans;
    return 0;
}