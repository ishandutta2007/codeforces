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

lint d[111111][2];

vector<pair<int, int> > g[111111];

void dfs(int v, int p) {
    lint mx = 0;
    for (auto& i : g[v]) {
        int to = i.first;
        int w = i.second;
        if (to == p) {
            continue;
        }
        dfs(to, v);
        d[v][0] += d[to][0] + 2 * w;
        mx = max(mx, d[to][0] - d[to][1] + w);
    }
    d[v][1] = d[v][0] - mx;
}

int main() {
    scid(n);
    for (int i = 1; i < n; i++) {
        sciiid(x, y, z);
        --x; --y;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    dfs(0, -1);

    cout << d[0][1];

    return 0;
}