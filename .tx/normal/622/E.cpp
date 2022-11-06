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

vector<int> g[555555];
int ds[555555];

int dfs(int v, int p, int d) {
    if (g[v].size() == 1) {
        ds[d]++;
        return d;
    }
    int res = 0;
    for (int i : g[v]) {
        if (i != p) {
            res = max(res, dfs(i, v, d + 1));
        }
    }
    return res;
}

int main() {
    scid(n);
    for (int i = 1; i < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;

    for (int i : g[0]) {
//        memset(ds, 0, sizeof(ds));
        int omx = dfs(i, 0, 1);
        int mx = 1;
        for (int j = 1; j < omx; j++) {
            if (ds[j] != 0) {
                mx = j;
            }
            if (ds[j] > 1) {
                ds[j + 1] += ds[j] - 1;
            }
        }
        if (ds[omx]) {
            mx = omx + ds[omx] - 1;
        }
        for (int j = 0; j <= omx; j++) {
            ds[j] = 0;
        }
        ans = max(ans, mx);
    }

    cout << ans;

    return 0;
}