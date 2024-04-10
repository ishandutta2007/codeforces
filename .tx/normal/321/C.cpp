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

vector<int> g[111111];
char ans[111111];
bool ban[111111];

int mn, center;

int dfs(int v, int p, int cn) {
    int mxSz = 0;
    int sSz = 1;
    for (int i : g[v]) {
        if (i == p || ban[i]) {
            continue;
        }
        int c = dfs(i, v, cn);
        sSz += c;
        mxSz = max(mxSz, c);
    }
    mxSz = max(mxSz, cn - sSz);
    if (mxSz < mn) {
        mn = mxSz;
        center = v;
    }
    return sSz;
}

int findCenter(int v) {
    int n = dfs(v, -1, 0);
    mn = 1e9;
    dfs(v, -1, n);
    return center;
}

void solve(int v, char c) {
    int x = findCenter(v);
    ans[x] = c;
    ban[x] = true;
    for (int i : g[x]) {
        if (!ban[i]) {
            solve(i, c + 1);
        }
    }
}

int main() {
    scid(n);
    for (int i = 0; i + 1 < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    solve(0, 'A');

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }


    return 0;
}