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

vector<int> g[333333];
int ans[333333];
int sz[333333];

void calcSz(int v, int p) {
    sz[v] = 1;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        calcSz(i, v);
        sz[v] += sz[i];
    }
}

deque<int> vs;

void go(int v, int p, int cv, int cn) {
    int mxi = -1;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        if (mxi == -1 || sz[i] > sz[mxi]) {
            mxi = i;
        }
    }
    while (mxi == -1 || sz[mxi] <= cn / 2) {
        ans[cv] = v;
        if (vs.empty()) {
            return;
        }
        cv = vs.front();
        vs.pop_front();
        cn = sz[cv];
    }
    vs.push_back(mxi);
    go(mxi, v, cv, cn);
}

void dfs(int v, int p) {
    if (ans[v] == -1) {
        go(v, p, v, sz[v]);
    }
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
    }
}

int main() {
    sciid(n, q);
    for (int i = 1; i < n; i++) {
        scid(x);
        --x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    calcSz(0, -1);
    memset(ans, -1, sizeof(ans));
    dfs(0, -1);

    while (q-- > 0) {
        scid(x);
        --x;
        cout << ans[x] + 1 << "\n";
    }

    return 0;
}