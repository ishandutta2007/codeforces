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

vector<int> g[4444];
int p[4444];
bool c[4444][4444];

int main() {
    sciid(n, m);

    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        p[x]++;
        p[y]++;
        c[x][y] = c[y][x] = true;
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            for (int k = j + 1; k < g[i].size(); k++) {
                if (c[g[i][j]][g[i][k]]) {
                    ans = min(ans, p[i] + p[g[i][j]] + p[g[i][k]]);
                    if (ans == 7) {
                        ans++;
                        ans -= 1;
                    }
                }
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans - 6);
    return 0;
}