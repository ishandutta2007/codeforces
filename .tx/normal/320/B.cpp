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

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

vector<int> l, r;
vector<bool> used;

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < l.size(); i++) {
        if (!used[i] && (l[i] < l[v] && l[v] < r[i] || l[i] < r[v] && r[v] < r[i])) {
            dfs(i);
        }
    }
}

int main() {
    scid(n);
    while (n-- > 0) {
        sciiid(t, x, y);
        if (t == 1) {
            l.push_back(x);
            r.push_back(y);
            used.push_back(false);
        } else {
            used.assign(l.size(), false);
            dfs(x - 1);
            puts(used[y - 1] ? "YES" : "NO");
        }
    }

    return 0;
}