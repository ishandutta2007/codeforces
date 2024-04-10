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

int ans[1111111];

int main() {
    sciid(n, k);
    if (3 * k > n) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < k; i++) {
        if ((i & 1) == 0) {
            ans[i * 3] = ans[i * 3 + 1] = ans[(i * 3 + 3) % n] = i;
        } else {
            ans[i * 3 - 1] = ans[i * 3 + 1] = ans[i * 3 + 2] = i;
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }

    return 0;
}