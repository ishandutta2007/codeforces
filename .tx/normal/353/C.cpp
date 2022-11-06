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

int main() {
    scid(n);
    rveid(a, n);
    string x;
    cin >> x;
    int sx = 0;
    vector<int> ps(n);
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            sx += a[i];
        }
        ps[i] = a[i];
        if (i > 0) {
            ps[i] += ps[i - 1];
        }
    }
    int ans = sx;
    int cs = 0;
    for (int i = n - 1; i > 0; i--) {
        if (x[i] == '1') {
            ans = max(ans, cs + ps[i - 1]);
            cs += a[i];
        }
    }
    cout << ans;
    return 0;
}