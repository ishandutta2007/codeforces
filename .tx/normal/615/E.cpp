#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int main() {
    lint n;
    cin >> n;

    n++;

    if (n == 1) {
        cout << "0 0";
        return 0;
    }

    lint l = 0, r = 1e9;
    while (l + 1 < r) {
        lint m = (l + r) >> 1;
        lint sk = 1 + 3 * m * (m + 1);
        if (sk >= n) {
            r = m;
        } else {
            l = m;
        }
    }

    lint k = r;
    lint sx = 1 + 2 * (k - 1);
    lint sy = 2;

    n -= 1 + 3 * k * (k - 1);

    int dx[7] = {-1, -2, -1, 1, 2, 1, -1};
    int dy[7] = {2, 0, -2, -2, 0, 2, 2};
    lint wl[7] = {k - 1, k, k, k, k, k, 1};

    for (int i = 0; i < 7; i++) {
        if (n <= wl[i]) {
            cout << sx + (n - 1) * dx[i] << " " << sy + (n - 1) * dy[i];
            return 0;
        }
        sx += wl[i] * dx[i];
        sy += wl[i] * dy[i];
        n -= wl[i];
    }

    cout << ":(";

    return 0;
}