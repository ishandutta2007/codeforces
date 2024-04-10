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

vector<int> g[111];
bool used[111];
int c[111];

int ans = 0;

int dfs(int v, int p) {
    used[v] = true;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        if (used[i] && c[i] == c[v]) {
            ans++;
            return 0;
        }
        if (!used[i]) {
            c[i] = 1 - c[v];
            return dfs(i, v);
        }
    }
    return 1 - c[v];
}


int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int c1 = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && g[i].size() <= 1) {
            c1 += dfs(i, -1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            c1 += dfs(i, -1);
        }
    }

    cout << ans + c1 % 2;

    return 0;
}