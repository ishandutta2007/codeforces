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

set<int> g[111111];

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        g[x].insert(y);
        g[y].insert(x);
    }

    set<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        st.insert({g[i].size(), i});
    }

    int ans = 0;

    while (!st.empty()) {
        auto v = *st.begin();
        st.erase(v);
        if (v.first == 0) {
            ans++;
            continue;
        } else if (v.first > 1) {
            break;
        }
        int to = *g[v.second].begin();
        st.erase({g[to].size(), to});
        g[to].erase(v.second);
        st.insert({g[to].size(), to});
    }

    cout << ans;

    return 0;
}