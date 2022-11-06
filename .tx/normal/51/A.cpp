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

char a[1111][3][3];
char buf[3];

bool has236(int x) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[x][i][j] == '3' || a[x][i][j] == '2' || a[x][i][j] == '6') {
                return true;
            }
        }
    }
    return false;
}

bool same(int x, int y) {
    bool has = false;
    auto& s = a[x];
    auto& t = a[y];

    if (s[0][0] == t[0][0] && s[0][1] == t[0][1] && s[1][0] == t[1][0] && s[1][1] == t[1][1]) {
        return true;
    }

    if (!has && s[0][0] == t[0][1] && s[0][1] == t[1][1] && s[1][0] == t[0][0] && s[1][1] == t[1][0]) {
        return true;
    }

    if (s[0][0] == t[1][1] && s[0][1] == t[1][0] && s[1][0] == t[0][1] && s[1][1] == t[0][0]) {
        return true;
    }

    if (!has && s[0][0] == t[1][0] && s[0][1] == t[0][0] && s[1][0] == t[1][1] && s[1][1] == t[0][1]) {
        return true;
    }
    return false;
}

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        if (i) {
            scanf("\n%s", buf);
        }
        scanf("\n%s", a[i][0]);
        scanf("\n%s", a[i][1]);
    }

    int ans = n;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (same(i, j)) {
                ans--;
                break;
            }
        }
    }

    cout << ans;




    return 0;
}