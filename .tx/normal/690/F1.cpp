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

vector<int> g[11111];
int sz[11111];
lint ans = 0;

void dfs(int v, int p) {
    sz[v] = 1;
    for (int i : g[v]) {
        if (i != p) {
            dfs(i, v);
            sz[v] += sz[i];
        }
    }
    int kc = g[v].size();
//    if (p != -1) {
//        kc--;
//    }
    ans += 1LL * kc * (kc - 1) / 2;
}

int main() {
    scid(n);
    for (int i = 1; i < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

    cout << ans;

    return 0;
}