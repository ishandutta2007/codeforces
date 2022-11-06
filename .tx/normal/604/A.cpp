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

using namespace std;

int main() {
    rveid(m, 5);
    rveid(w, 5);
    sciid(s, f);
    int ans = 100 * s - 50 * f;
    for (int i = 1; i <= 5; i++) {
        ans += max(3 * i * 50, i * 500 - m[i - 1] * 2 * i - 50 * w[i - 1]);
    }
    cout << ans;

    return 0;
}