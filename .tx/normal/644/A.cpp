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

int a[111][111];

int main() {
    sciiid(x, n, m);
    int c1 = 1, c2 = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                if (c1 <= x) {
                    a[i][j] = c1;
                    c1 += 2;
                }
            } else {
                if (c2 <= x) {
                    a[i][j] = c2;
                    c2 += 2;
                }
            }
        }
    }
    if (c1 <= x || c2 <= x) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}