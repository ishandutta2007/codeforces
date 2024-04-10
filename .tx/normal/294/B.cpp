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

vector<int> a[2];

int ps[2][111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(t, w);
        a[--t].push_back(w);
    }
    sort(a[0].rbegin(), a[0].rend());
    sort(a[1].rbegin(), a[1].rend());
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            ps[i][j] = a[i][j];
            if (j) {
                ps[i][j] += ps[i][j - 1];
            }
        }
    }
    int ans = 1e9;
    for (int t1 = 0; t1 <= a[1].size(); t1++) {
        int rw = ps[1][a[1].size() - 1] - (t1 == 0 ? 0 : ps[1][t1 - 1]);
        for (int t0 = 0; t0 <= a[0].size(); t0++) {
            int rw0 = ps[0][a[0].size() - 1] - (t0 == 0 ? 0 : ps[0][t0 - 1]);
            if (t1 * 2 + t0 >= rw + rw0) {
                ans = min(ans, t1 * 2 + t0);
            }
        }
    }
    cout << ans;

    return 0;
}