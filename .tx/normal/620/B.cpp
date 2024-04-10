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

int x[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int sbc(int a) {
    if (a == 0) {
        return x[0];
    }
    int res = 0;
    while (a) {
        res += x[a % 10];
        a /= 10;
    }
    return res;
}

int main() {
    sciid(a, b);

    lint ans = 0;
    for (int i = a; i <= b; i++) {
        ans += sbc(i);
    }
    cout << ans;
    return 0;
}