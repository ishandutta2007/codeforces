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

vector<pair<int, int> > g[222222];

int dfs1(int v, int p) {
    int res = 0;
    for (auto& i : g[v]) {
        if (i.first != p) {
            res += i.second + dfs1(i.first, v);
        }
    }
    return res;
}

int ans[222222];

void dfs2(int v, int p, int ca) {
    ans[v] = ca;
    for (auto& i : g[v]) {
        if (i.first != p) {
            dfs2(i.first, v, ca + (i.second == 0 ? 1 : -1));
        }
    }
}

int main() {
    scid(n);
    for (int i = 0; i + 1 < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }

    ans[0] = dfs1(0, -1);
    dfs2(0, -1, ans[0]);

    int mn = *min_element(ans, ans + n);
    cout << mn << "\n";
    for (int i = 0; i < n; i++) {
        if (ans[i] == mn) {
            cout << i + 1 << " ";
        }
    }


    return 0;
}