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
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int d[55555][555];
vector<int> g[55555];

lint ans = 0;
int n, k;

void dfs(int v, int p) {
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        for (int j = 1; j <= k; j++) {
            d[v][j] += d[i][j - 1];
        }
    }
    ans += d[v][k];
    lint t = 0;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        for (int j = 0; j + 2 <= k; j++) {
            t += 1LL * d[i][j] * (d[v][k - j - 1] - d[i][k - j - 2]);
        }
    }
    t /= 2;
    ans += t;
}

int main() {
    scii(n, k);
    for (int i = 1; i < n; i++) {
        sciid(a, b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        d[i][0] = 1;
    }
    dfs(0, -1);
    cout << ans;
    return 0;
}