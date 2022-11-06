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

int a[111111];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scid(n);
    int k0 = 0;
    int kl = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (a[i] == 0) {
            k0++;
        }
        if (a[i] < 0) {
            kl++;
        }
    }
    int ans = 1e9;
    int km = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] < 0) {
            kl--;
        }
        if (a[i] > 0) {
            km++;
        }
        ans = min(ans, km + kl + k0);
    }
    cout << ans;
    return 0;
}