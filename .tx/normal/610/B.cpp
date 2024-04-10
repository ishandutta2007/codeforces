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

int a[222222];

int main() {
    scid(n);
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
    }
    int mn = *min_element(a, a + n);
    lint ans = 1LL * n * mn;
    auto it = find(a, a + n, mn);
    rotate(a, it, a + n);
    a[n++] = mn;
    int mx = 0;
    int last = -1;
    for (int i = 1; i < n; i++) {
        if (last == -1 && a[i] > mn) {
            last = i;
        }
        if (last != -1 && a[i] == mn) {
            mx = max(mx, i - last);
            last = -1;
        }
    }
    cout << ans + mx;
    return 0;
}