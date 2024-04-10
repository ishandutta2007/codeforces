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
int b[111111];

int main() {
    sciid(n, k);
    n /= k;
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        sci(b[i]);
    }
    lint ans = 1;
    lint mod = 1e9 + 7;
    int p10 = 1;
    for (int i = 0; i < k; i++) {
        p10 *= 10;
    }
    for (int i = 0; i < n; ++i) {
        int k1 = (p10 - 1 + a[i]) / a[i];
        int t = k1;

        k1 = (p10 / 10 * (b[i] + 1) - 1 + a[i]) / a[i];
        int k0 = (p10 / 10 * b[i] - 1 + a[i]) / a[i];
        t -= k1 - k0;

        ans = ans * t % mod;
    }
    cout << ans;

    return 0;
}