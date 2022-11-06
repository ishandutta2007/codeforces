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

vector<int> g[111][111];

void dfs(int x, int v, int p, int d, int& mx, int& mv) {
    if (d > mx) {
        mx = d;
        mv = v;
    }
    for (int i : g[x][v]) {
        if (i != p) {
            dfs(x, i, v, d + 1, mx, mv);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        for (int j = 0; j + 1 < x; j++) {
            sciid(a, b);
            --a; --b;
            g[i][a].push_back(b);
            g[i][b].push_back(a);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mx = 0, mv = 0;
        dfs(i, 0, -1, 0, mx, mv);
        dfs(i, mv, -1, 0, mx, mv);
        ans += mx;
    }
    cout << ans;

    return 0;
}