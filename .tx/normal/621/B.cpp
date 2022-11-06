#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int d1[2222];
int d2[2222];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        d1[x + y]++;
        d2[x - y + 1000]++;
    }
    lint ans = 0;
    for (int i = 0; i < 2222; i++) {
        ans += 1LL * d1[i] * (d1[i] - 1) / 2;
        ans += 1LL * d2[i] * (d2[i] - 1) / 2;
    }

    cout << ans;

    return 0;
}