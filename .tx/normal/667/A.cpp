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

const double PI = acos(-1.0);
const double eps = 1e-9;

int main() {
    double d, h, v, e;
    init_cin
    cin >> d >> h >> v >> e;
    d /= 2;

    e = PI * d * d * e;

    if (e > v - eps) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    printf("%.11f", PI * d * d * h / (v - e));

    return 0;
}