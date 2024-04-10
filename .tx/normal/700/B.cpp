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

bool un[222222];
int sz[222222];
vector<int> g[222222];

lint ans = 0;

void calcSz(int v, int p, int d) {
    if (un[v]) {
        sz[v] = 1;
        ans += d;
    }
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        calcSz(i, v, d + 1);
        sz[v] += sz[i];
    }
}

void dfs(int v, int p, int d, int k, int td) {
    int mx = -1;
    int s = sz[v] - td;
    int mxi = -1;
    for (int i : g[v]) {
        if (i != p) {
            if (sz[i] > mx) {
                mx = sz[i];
                mxi = i;
            }
        }
    }
    if (mx - td <= s / 2) {
        ans -= 1LL * s * d;
        return;
    }

    int x = s + td - mx;
    ans -= 1LL * x * d * 2;
    dfs(mxi, v, d + 1, k, td + x);
}

int main() {
    sciid(n, k);
    k *= 2;
    for (int i = 0; i < k; i++) {
        scid(x);
        --x;
        un[x] = true;
    }

    for (int i = 0; i + 1 < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    calcSz(0, -1, 0);
    dfs(0, -1, 0, k, 0);

    cout << ans;

    return 0;
}