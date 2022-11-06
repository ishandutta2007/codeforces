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

vector<int> g[111111];

lint ans = 0;

int maxLen[111111];

int dfs(int v) {
    if (maxLen[v] != -1) {
        return maxLen[v];
    }
    maxLen[v] = 1;
    for (int i : g[v]) {
        if (i < v) {
            maxLen[v] = max(maxLen[v], dfs(i) + 1);
        }
    }
    return maxLen[v];
}

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        g[--x].push_back(--y);
        g[y].push_back(x);
    }

    memset(maxLen, -1, sizeof(maxLen));

    for (int i = 0; i < n; i++) {
        ans = max(ans, (const lint &) (dfs(i) * 1LL * g[i].size()));
    }
    cout << ans;

    return 0;
}