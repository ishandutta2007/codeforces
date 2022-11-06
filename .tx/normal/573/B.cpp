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

#define rveid(a, n) vector<int> (a)(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int l[111111];
int r[111111];

int main() {
    scid(n);
    rveid(h, n);
    l[0] = 1;
    for (int i = 1; i < n; i++) {
        l[i] = min(h[i], l[i - 1] + 1);
    }
    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        r[i] = min(h[i], r[i + 1] + 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(l[i], r[i]));
    }
    cout << ans;
    return 0;
}