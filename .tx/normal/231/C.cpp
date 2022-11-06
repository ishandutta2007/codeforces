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

int a[111111];
lint ps[111111];

int main() {
    sciid(n, k);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    sort(a, a + n);
    ps[0] = a[0];
    for (int i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + a[i];
    }
    int ans = 0;
    int ai = -1;
    int i = 0;
    while (i < n) {
        int l = 0, r = i + 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            lint na = 1LL * a[i] * m - (ps[i - 1] - ((i - 1 - m) >= 0 ? ps[i - 1 - m] : 0));
            if (na <= k) {
                l = m;
            } else {
                r = m;
            }
        }
        while (i + 1 < n && a[i + 1] == a[i]) {
            i++;
            l++;
        }
        if (l + 1 > ans) {
            ans = l + 1;
            ai = a[i];
        }
        i++;
    }

    cout << ans << " " << ai;
    return 0;
}