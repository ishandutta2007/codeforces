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

int ans[111111];

int main() {
    scid(n);
    if (n % 4 != 0 && n % 4 != 1) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n / 2; i += 2) {
        ans[i] = i + 2;
        ans[i + 1] = n - i;
        ans[n - 1 - i] = n - i - 1;
        ans[n - 1 - i - 1] = i + 1;
    }
    if (n % 2 == 1) {
        ans[n / 2] = (n + 1) / 2;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}