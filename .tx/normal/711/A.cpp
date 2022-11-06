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

char a[1111][11];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scanf("\n%s", a[i]);
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j += 3) {
            if (a[i][j] == 'O' && a[i][j + 1] == 'O') {
                a[i][j] = a[i][j + 1] = '+';
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }

    if (!ok) {
        cout << "NO";
    } else {
        puts("YES");
        for (int i = 0; i < n; i++) {
            puts(a[i]);
        }
    }

    return 0;
}