#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int main() {
    int n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;
    int m = (n + k - 1) / k;
    double x = m + (m - 1) * 1.0 * (v2 - v1) / (v2 + v1);
    double y = 1 - 1.0 * v2 / v1;
    double t = 1.0 * l / v1 / (x - y);
    double T = x * t;
    printf("%.11f", T);

    return 0;
}