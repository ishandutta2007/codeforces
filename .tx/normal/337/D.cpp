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
typedef long double ldouble;

using namespace std;

vector<int> g[111111];
int dd[111111];
int du[111111];
bool bad[111111];

void dfs(int v, int p) {
    int cur = bad[v] ? 0 : -1e9;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        if (dd[i] != -1e9) {
            cur = max(cur, dd[i] + 1);
        }
    }
    dd[v] = cur;
}

void dfs2(int v, int p, int cu) {
    if (bad[v]) {
        cu = max(cu, 0);
    }
    du[v] = cu;
    int deg = g[v].size();
    if (p != -1) {
        deg--;
    }
    if (deg == 0) {
        return;
    }
    vector<int> pref(deg);
    int cx = 0;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        pref[cx++] = dd[i] + 1;
    }
    vector<int> suf(pref);
    for (int i = 1; i < deg; i++) {
        pref[i] = max(pref[i], pref[i - 1]);
        suf[deg - 1 - i] = max(suf[deg - 1 - i], suf[deg - i]);
    }
    cx = 0;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        int cur = -1e9;
        if (cu != -1e9) {
            cur = max(cur, cu + 1);
        }
        if (cx > 0) {
            cur = max(cur, pref[cx - 1] + 1);
        }
        if (cx + 1 < deg) {
            cur = max(cur, suf[cx + 1] + 1);
        }
        dfs2(i, v, cur);
        cx++;
    }
}

int main() {
    sciiid(n, m, d);
    for (int i = 0; i < m; i++) {
        scid(x);
        bad[--x] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        sciid(x, y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    dfs2(0, -1, -1e9);
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (max(dd[i], du[i]) > d) {
            ans--;
        }
    }
    cout << ans;


    return 0;
}