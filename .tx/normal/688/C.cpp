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
int col[111111];

void dfs(int v, int c) {
    col[v] = c;
    for (int i : g[v]) {
        if (col[i] == -1) {
            dfs(i, 1 - c);
        } else if (col[i] == c) {
            cout << -1;
            exit(0);
        }
    }
}

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    memset(col, -1, sizeof(col));

    int ls = 0;

    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            dfs(i, ls);
            ls = 1 - ls;
        }
    }

    vector<int> a[2];
    for (int i = 0; i < n; i++) {
        a[col[i]].push_back(i);
    }

    for (int i = 0; i < 2; i++) {
        cout << a[i].size() << "\n";
        for (int j : a[i]) {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }


    return 0;
}