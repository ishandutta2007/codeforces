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

int a[111];

vector<int> g[111];
bool used[111];

void dfs(int v) {
    used[v] = true;
    for (int i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
}

int main() {
    scid(n);
    rea(a, n);
    for (int i = 0; i < n; i++) {
        scid(x);
        if (i - x >= 0) {
            g[i].push_back(i - x);
            g[i - x].push_back(i);
        }
        if (i + x < n) {
            g[i].push_back(i + x);
            g[i + x].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        memset(used, 0, sizeof(used));
        dfs(i);
        if (!used[--a[i]]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}