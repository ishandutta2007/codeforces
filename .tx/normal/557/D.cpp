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

int col[111111];
vector<int> g[111111];

bool dfs(int v, int c, pair<int, int>& cs) {
    col[v] = c;
    cs.first++;
    for (int i : g[v]) {
        if (col[i] == c) {
            return true;
        }
        if (col[i] == -1) {
            swap(cs.first, cs.second);
            if (dfs(i, 1 - c, cs)) {
                return true;
            }
            swap(cs.first, cs.second);
        }
    }
    return false;
}

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    memset(col, -1, sizeof(col));

    vector<pair<int, int> > ps;

    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            pair<int, int> cs = make_pair(0, 0);
            if (dfs(i, 0, cs)) {
                cout << "0 1";
                return 0;
            }
            ps.push_back(cs);
        }
    }

    sort(ps.begin(), ps.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first + a.second > b.first + b.second;
    });

    if (ps[0].first + ps[0].second >= 3) {
        lint ans = 0;
        int i = 0;
        while (i < ps.size() && ps[i].first + ps[i].second >= 3) {
            lint l = ps[i].first;
            lint r = ps[i].second;
            ans += l * (l - 1) / 2 + r * (r - 1) / 2;
            i++;
        }
        cout << "1 " << ans;
        return 0;
    }

    if (m > 0) {
        cout << "2 " << (1LL * m * (n - 2));
        return 0;
    }
    cout << "3 " << 1LL * n * (n - 1) * (n - 2) / 6;


    return 0;
}