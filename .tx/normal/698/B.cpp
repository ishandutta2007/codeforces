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

int a[222222];
bool used[222222];
vector<int> g[222222];

int dfs(int v, int p = -1) {
    used[v] = true;
    int res = -1;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        if (!used[i]) {
            int x = dfs(i, v);
            if (x != -1) {
                res = x;
            }
        } else {
            res = i;
        }
    }
    return res;
}

int main() {
    scid(n);
    bool hRoot = false;
    int root = -1;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        --a[i];
        if (a[i] == i) {
            hRoot = true;
            root = i;
        }
        g[i].push_back(a[i]);
        g[a[i]].push_back(i);
    }

    if (!hRoot) {
        root = dfs(0);
        a[root] = root;
        fill(used, used + n, false);
    }

    for (int i = 0; i < n; i++) {
        g[i].clear();
    }

    for (int i = 0; i < n; i++) {
        g[i].push_back(a[i]);
        g[a[i]].push_back(i);
    }

    int cc = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            bool wRoot = used[root];
            int x = dfs(i);
            if (!wRoot && used[root]) {
                continue;
            }
            cc++;
            a[x] = root;
        }
    }

    if (!hRoot) {
        cc++;
    }

    cout << cc << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << " ";
    }


    return 0;
}