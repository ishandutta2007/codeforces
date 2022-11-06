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

int a[22222][11];
int s[11];
int b[22222][11];

int main() {
    sciiid(n, m, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sci(a[i][j]);
        }
    }

    while (k-- > 0) {
        sciid(x, y);
        --x; --y;
        s[y]++;
        b[x][y]++;
    }

    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                x += s[j] - b[i][j];
            }
        }

        cout << x << " ";
    }


    return 0;
}