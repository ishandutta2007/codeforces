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

int c[111111];
bool isCap[111111];

int main() {
    sciid(n, k);
    rvei(c, n);
    for (int i = 0; i < k; i++) {
        scid(x);
        --x;
        isCap[x] = true;
    }

    lint s = 0;
    for (int i = 0; i < n; i++) {
        s += c[i];
    }

    lint ans = 0;

    for (int i = 0; i < n; i++) {
        if (isCap[i]) {
            s -= c[i];
            ans += s * c[i];
        } else {
            int nx = (i + 1) % n;
            if (!isCap[nx]) {
                ans += c[i] * (c[nx]);
            }
        }
    }

    cout << ans;

    return 0;
}