#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

vector<int> g[111111];
bool isHotel[111111];
int maxD[111111];

int dfs(int v) {
    if (isHotel[v]) {
        return 1;
    }
    if (g[v].size() != 1) {
        return 0;
    }
    if (maxD[v] != -1) {
        return maxD[v];
    }
    maxD[v] = 0;
    int x = dfs(g[v][0]);
    if (x != 0) {
        x++;
    }
    return maxD[v] = x;
}

void printPath(int v) {
    cout << v + 1 << " ";
    if (!isHotel[v]) {
        printPath(g[v][0]);
    }
}

int main() {
    scid(n);
    for (int i = 0; i < n; ++i) {
        scid(x);
        isHotel[i] = x == 1;
    }
    for (int i = 0; i < n; i++) {
        scid(x);
        if (x != 0) {
            g[--x].push_back(i);
        }
    }

    memset(maxD, -1, sizeof(maxD));

    int ans = 0;
    int from = -1;
    for (int i = 0; i < n; i++) {
        int x = dfs(i);
        if (x > ans) {
            ans = x;
            from = i;
        }
    }
    cout << ans << "\n";
    if (ans > 0) {
        printPath(from);
    }

    return 0;
}