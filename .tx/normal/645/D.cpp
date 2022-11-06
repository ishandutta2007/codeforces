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

set<int> g[111111];

pair<int, int> es[111111];
int ts[111111];
int tsx;

bool used[111111];

void dfs(int v) {
    used[v] = true;
    for (int i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
    ts[tsx++] = v;
}

int n;

bool check(int md) {
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    for (int i = 0; i < md; i++) {
        g[es[i].first].insert(es[i].second);
    }
    tsx = 0;
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(ts, ts + n);
    for (int i = 0; i + 1 < n; i++) {
        if (g[ts[i]].find(ts[i + 1]) == g[ts[i]].end()) {
            return false;
            break;
        }
    }
    return true;
}

int main() {
    sci(n);
    scid(m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        es[i] = {x, y};
    }

    int l = 0, r = m;
    while (l + 1 < r) {
        int md = (l + r) >> 1;

        if (check(md)) {
            r = md;
        } else {
            l = md;
        }
    }
    if (check(r)) {
        cout << r;
    } else {
        cout << -1;
    }


    return 0;
}