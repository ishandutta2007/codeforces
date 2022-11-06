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
    sciid(a, ta);
    sciid(b, tb);
    int xh, x;
    scanf("%d:%d", &xh, &x);
    x += xh * 60;
    int y = x + ta;
    int fs = 5 * 60;
    int ls = 23 * 60 + 59;
    int ans = 0;
    for (int i = fs; i <= ls; i += b) {
        if (i < y && i + tb > x) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}