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

char s[111][111];

int main() {
    sciid(n, d);
    for (int i = 0; i < d; i++) {
        scanf("\n%s", s[i]);
    }

    int ans = 0;
    int cur = 0;
    for (int i = 0; i < d; i++) {
        bool win = false;
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '0') {
                win = true;
                break;
            }
        }
        if (win) {
            cur++;
        } else {
            ans = max(ans, cur);
            cur = 0;
        }
    }

    ans = max(ans, cur);
    cout << ans;

    return 0;
}