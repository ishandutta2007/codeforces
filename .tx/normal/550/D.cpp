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

int d[1111];

#define pre(a, b) printf("%d %d\n", a + 1, b + 1)

int main() {
    scid(k);
    if (k % 2 == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    int n = 2 * (2 * k - 1);
    int m = n * k / 2;
    cout << n << " " << m << "\n";

    pre(0, 2 * k - 1);
    for (int add = 0; add <= 2 * k - 1; add += 2 * k - 1) {
        for (int i = 1; i < k; i++) {
            for (int j = k; j < 2 * k - 1; j++) {
                pre(i + add, j + add);
            }
        }
        for (int i = 1; i < k; i += 2) {
            pre(i + add, i + 1 + add);
        }
        for (int j = k; j < 2 * k - 1; j++) {
            pre(add, j + add);
        }
    }

    return 0;
}