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

bool urow[111111];
bool ucol[111111];

int main() {
    sciid(n, m);
    lint cur = 1LL * n * n;
    int krow = 0;
    int kcol = 0;
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        if (!urow[x] && !ucol[y]) {
            cur -= 2 * n - 1 - krow - kcol;
            krow++;
            kcol++;
        } else if (!urow[x]) {
            cur -= n - kcol;
            krow++;
        } else if (!ucol[y]) {
            cur -= n - krow;
            kcol++;
        }
        urow[x] = ucol[y] = true;
        cout << cur << " ";
    }

    return 0;
}