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

vector<pair<int, int> > g[1111];

pair<int, int> dfs(int v) {
    if (g[v].empty()) {
        return {v, 1e9};
    }
    auto r = dfs(g[v][0].first);
    r.second = min(r.second, g[v][0].second);
    return r;
}

bool canIn[1111];

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciiid(x, y, z);
        --x; --y;
        g[x].push_back({y, z});
        canIn[y] = true;
    }
    int as = 0;
    for (int i = 0; i < n; i++) {
        if (!canIn[i] && !g[i].empty()) {
            as++;
        }
    }
    cout << as << "\n";
    for (int i = 0; i < n; i++) {
        if (!canIn[i] && !g[i].empty()) {
            auto r = dfs(i);
            cout << i + 1 << " " << r.first + 1 << " " << r.second << "\n";
        }
    }

    return 0;
}