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

lint d[2][11];
lint a[222222];
lint l[222222];
lint r[222222];

int main() {
    sciiid(n, k, x);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    lint xk = 1;
    for (int i = 0; i < k; i++) {
        xk *= x;
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        l[i] = a[i];
        if (i != 0) {
            l[i] |= l[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        r[i] = a[i];
        if (i != n - 1) {
            r[i] |= r[i + 1];
        }
    }
    for (int i = 0; i < n; i++) {
        lint t = 0;
        if (i != 0) {
            t |= l[i - 1];
        }
        if (i != n - 1) {
            t |= r[i + 1];
        }
        t |= a[i] * xk;
        ans = max(ans, t);
    }
    cout << ans;
    return 0;
}