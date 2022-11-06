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

vector<pair<int, int> > g[111111];
int sz[111111];
int a[111111];

void calcsz(int v, int p) {
    sz[v] = 1;
    for (auto& i : g[v]) {
        if (i.first != p) {
            calcsz(i.first, v);
            sz[v] += sz[i.first];
        }
    }
}

int ans = 0;

void dfs(int v, int p, lint md) {
    if (a[v] < md) {
        ans += sz[v];
        return;
    }

    for (auto& i : g[v]) {
        if (i.first == p) {
            continue;
        }
        dfs(i.first, v, max(0LL, md + i.second));
    }
}

int main() {
    scid(n);
    rea(a, n);
    for (int i = 1; i < n; i++) {
        sciid(x, y);
        --x;
        g[i].push_back({x, y});
        g[x].push_back({i, y});
    }

    calcsz(0, -1);
    dfs(0, -1, 0);

    cout << ans;

    return 0;
}