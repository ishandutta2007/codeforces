#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

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

vector<pair<int, int> > g[111111];
lint d[111111];

vector<pair<int, int> > ts[111111];
bool used[111111];

#define mmin(a, b) a < b ? a : b

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciiid(x, y, z);
        --x; --y;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    for (int i = 0; i < n - 1; i++) {
        scid(x);
        for (int j = 0; j < x; j++) {
            scid(y);
            ts[i].push_back({y, -1});
        }
        for (int j = x - 1; j >= 0; j--) {
            if (j == x - 1 || ts[i][j].first + 1 != ts[i][j + 1].first) {
                ts[i][j].second = ts[i][j].first + 1;
            } else {
                ts[i][j].second = ts[i][j + 1].second;
            }
        }
    }

    priority_queue<pair<lint, int> > q;
    int st = 0;
    if (!ts[0].empty() && ts[0][0].first == 0) {
        st = ts[0][0].second;
    }
    q.push({-st, 0});
    d[0] = st;
    for (int i = 1; i < n; i++) {
        d[i] = 1e18;
    }
    while (!q.empty()) {
        auto pv = q.top();
        q.pop();
        int v = pv.second;
        if (used[v]) {
            continue;
        }
        used[v] = true;
        for (auto& i : g[v]) {
            int to = i.first;
            int cost = i.second;
            lint t = d[v] + cost;
            int l = upper_bound(ts[to].begin(), ts[to].end(), make_pair<int, int>(mmin(t, 2e9), 2e9)) - ts[to].begin() - 1;
//            int l = -1, r = ts[to].size();
//            while (l + 1 < r) {
//                int m = (l + r) >> 1;
//                if (ts[to][m].first > t) {
//                    r = m;
//                } else {
//                    l = m;
//                }
//            }
            if (l != -1 && ts[to][l].first == t) {
                t = ts[to][l].second;
            }
            if (d[to] > t) {
                d[to] = t;
                q.push({-d[to], to});
            }
        }
    }

    if (d[n - 1] == 1e18) {
        cout << -1;
    } else {
        cout << d[n - 1];
    }


    return 0;
}