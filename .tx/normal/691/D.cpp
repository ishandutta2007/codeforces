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

int a[1111111];
vector<int> g[1111111];
int c[1111111];
vector<int> nums[1111111];
vector<int> ids[1111111];


void dfs(int v, int cc) {
    c[v] = cc;
    for (int i : g[v]) {
        if (c[i] == -1) {
            dfs(i, cc);
        }
    }
}

int main() {
    sciid(n, m);
    rea(a, n);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    memset(c, -1, sizeof(c));
    int cc = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == -1) {
            dfs(i, cc++);
        }
    }

    for (int i = 0; i < n; i++) {
        nums[c[i]].push_back(a[i]);
        ids[c[i]].push_back(i);
    }

    for (int i = 0; i < cc; i++) {
        sort(nums[i].rbegin(), nums[i].rend());
        for (int j = 0; j < nums[i].size(); j++) {
            a[ids[i][j]] = nums[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }



    return 0;
}