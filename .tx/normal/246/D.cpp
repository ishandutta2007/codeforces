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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int c[111111];
set<int> d[111111];

int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        sci(c[i]);
        d[c[i]].insert(c[i]);
    }
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x;
        --y;
//        if (c[x] != c[y]) {
            d[c[x]].insert(c[y]);
            d[c[y]].insert(c[x]);
//        }
    }
    int mx = 0;
    for (int i = 1; i < 111111; i++) {
        if (d[i].size() > d[mx].size()) {
            mx = i;
        }
    }
    cout << mx;
    return 0;
}