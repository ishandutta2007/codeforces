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

int d1[222222];
int d2[222222];

vector<int> g[222222];

int dfs(int v, int p) {
    if (p != -1 && g[v].size() == 1) {
        return d1[v] = d2[v] = 1;
    }
    int s1 = 0, s2 = 0;
    int m1 = -1, m2 = -1;

    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        if (m1 == -1 || d1[i] - d2[i] < m1) {
            m2 = m1;
            m1 = d1[i] - d2[i];
        } else if (m2 == -1 || d1[i] - d2[i] < m2) {
            m2 = d1[i] - d2[i];
        }
        s1 += d1[i];
        s2 += d2[i];
    }

    d1[v] = min(s2 + 1, s2 + m1);
    d2[v] = d1[v];
    if (m2 != -1) {
        d2[v] = min(d2[v], s2 + m1 + m2 - 1);
    }
    return d2[v];
}

int main() {
    sciiid(n, x, y);
    if (n == 2) {
        cout << x;
        return 0;
    }
    if (n == 3) {
        cout << min(2 * x, x + y);
        return 0;
    }
//    if (x >= y) {
//        cout << 1LL * (n - 1) * y;
//        return 0;
//    }

    bool wall = false;

    for (int i = 0; i + 1 < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        if (g[x].size() == n - 1 || g[y].size() == n - 1) {
            wall = true;
        }
    }

    if (x >= y) {
        if (!wall) {
            cout << 1LL * (n - 1) * y;
        } else {
            cout << 1LL * (n - 2) * y + x;
        }
        return 0;
    }

    int cp = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            cp = dfs(i, -1);
            break;
        }
    }

    cout << 1LL * (n - cp) * x + 1LL * (cp - 1) * y;

    return 0;
}