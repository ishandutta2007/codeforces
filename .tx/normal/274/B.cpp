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

vector<int> g[111111];
int a[111111];
lint cp[111111], cm[111111];

void dfs(int v, int p) {
    lint mxp = 0, mxm = 0;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        mxp = max(mxp, cp[i]);
        mxm = max(mxm, cm[i]);
    }
    lint x = a[v] + mxp - mxm;
    if (x < 0) {
        cp[v] = mxp - x;
        cm[v] = mxm;
    } else {
        cp[v] = mxp;
        cm[v] = mxm + x;
    }
}

int main() {
    scid(n);
    for (int i = 0; i + 1 < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    dfs(0, -1);
    cout << cp[0] + cm[0];

    return 0;
}