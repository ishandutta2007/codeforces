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

bool isStorage[111111];
pair<pair<int, int>, int> es[111111];

int main() {
    sciiid(n, m, k);
    for (int i = 0; i < m; i++) {
        sciiid(x, y, z);
        --x; --y;
        es[i] = {{x, y}, z};
    }

    for (int i = 0; i < k; i++) {
        scid(x);
        --x;
        isStorage[x] = true;
    }

    int ans = 1e9 + 10;
    for (int i = 0; i < m; i++) {
        if (isStorage[es[i].first.first] ^ isStorage[es[i].first.second]) {
            ans = min(ans, es[i].second);
        }
    }

    if (ans == 1e9 + 10) {
        cout << -1;
    } else {
        cout << ans;
    }


    return 0;
}