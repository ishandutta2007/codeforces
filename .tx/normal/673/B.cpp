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
int c[111111];
int mx[3];
int mn[3];

bool dfs(int v, int cc) {
    c[v] = cc;
    mx[cc] = max(mx[cc], v);
    mn[cc] = min(mn[cc], v);
    for (int i : g[v]) {
        if (c[i] == cc) {
            return false;
        }
        if (cc == 1 && i < v) {
            return false;
        }
        if (cc == 2 && i > v) {
            return false;
        }
        if (c[i] == 0) {
            if (!dfs(i, 3 - cc)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    sciid(n, m);
    if (m == 0) {
        cout << n - 1;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    mx[1] = mx[2] = -1;
    mn[1] = mn[2] = n;

    for (int i = 0; i < n; i++) {
        if (!g[i].empty() && c[i] == 0) {
            if (!dfs(i, 1)) {
                cout << 0;
                return 0;
            }
        }
    }

    if (mx[1] > mn[2]) {
        cout << 0;
        return 0;
    }

    int cb = 0;
    for (int i = mx[1] + 1; i < mn[2]; i++) {
        if (g[i].empty()) {
            cb++;
        }
    }

    cout << cb + 1;



    return 0;
}