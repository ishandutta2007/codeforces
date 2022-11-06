#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

vector<int> g[111111];
bool cat[111111];

int ans = 0;

void dfs(int v, int p, int c, int m) {
    if (c > m) {
        return;
    }
    bool leaf = true;
    for (int i : g[v]) {
        if (i != p) {
            leaf = false;
            dfs(i, v, cat[i] ? c + 1 : 0, m);
        }
    }
    if (leaf) {
        ans++;
    }
}

int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        scid(x);
        cat[i] = x == 1;
    }
    for (int i = 0; i + 1 < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1, cat[0] ? 1 : 0, m);
    cout << ans;

    return 0;
}