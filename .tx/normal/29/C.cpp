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

map<int, vector<int> > g;
vector<int> ans;
map<int, bool> used;

void dfs(int v) {
    used[v] = true;
    for (int i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
    ans.push_back(v);
}

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (auto& i : g) {
        if (i.second.size() == 1) {
            dfs(i.first);
            break;
        }
    }

    for (int i : ans) {
        cout << i + 1 << " ";
    }

    return 0;
}