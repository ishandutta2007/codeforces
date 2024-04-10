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

vector<int> g[55555];

int ans[55555];

void dfs(int v, int p) {
    if (p != -1) {
        ans[v] = p;
    }
    for (int i : g[v]) {
        if (i != p) {
            dfs(i, v);
        }
    }
}

int main() {
    sciiid(n, r1, r2);
    --r1; --r2;
    for (int i = 0; i < n; i++) {
        if (i == r1) {
            continue;
        }
        scid(x);
        --x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    dfs(r2, -1);

    for (int i = 0; i < n; i++) {
        if (i != r2) {
            cout << ans[i] + 1 << " ";
        }
    }



    return 0;
}