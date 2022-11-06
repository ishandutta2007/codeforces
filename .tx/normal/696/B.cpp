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
double ans[111111];
int sz[111111];

void calcSz(int v, int p) {
    int s = 0 ;
    for (int i : g[v]) {
        if (i != p) {
            calcSz(i, v);
            s += sz[i];
        }
    }
    sz[v] = s + 1;
}

void dfs(int v, int p) {
    int s = sz[v] - 1;
    ans[v] += 1;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        ans[i] += (s - sz[i]) / 2.0 + ans[v];
        dfs(i, v);
    }
}

int main() {
    scid(n);
    for (int i = 1; i < n; i++) {
        scid(x);
        --x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    calcSz(0, -1);
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        printf("%.8f ", ans[i]);
    }

    return 0;
}