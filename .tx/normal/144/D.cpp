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

struct edge {
    int to, w;
};

vector<edge> g[111111];

int main() {
    sciiid(n, m, s);
    --s;
    for (int i = 0; i < m; i++) {
        sciiid(x, y, z);
        --x; --y;
        g[x].push_back(edge{y, z});
        g[y].push_back(edge{x, z});
    }
    scid(l);
    if (l == 0) {
        cout << 1;
        return 0;
    }
    int ans = 0;

    vector<int> d(n, 1e9);
    vector<int> p(n, -1);
    d[s] = 0;
    priority_queue<pair<int, int> > q;
    q.push({0, s});
    vector<bool> used(n, false);
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int v = it.second;
        if (used[v]) {
            continue;
        }
        used[v] = true;
        for (edge& e : g[v]) {
            if (d[e.to] > d[v] + e.w) {
                d[e.to] = d[v] + e.w;
                q.push({-d[e.to], e.to});
                p[e.to] = v;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i] == l) {
            ans++;
            continue;
        }
        if (d[i] > l) {
            continue;
        }
        for (edge& e : g[i]) {
            if (d[e.to] > l) {
                ans++;
                continue;
            }
            if (d[e.to] == l && d[i] + e.w > l) {
                ans++;
                continue;
            }
            if (i > e.to) {
                continue;
            }
            if (e.w > l - d[i]) {
                int ol = d[e.to] + e.w - (l - d[i]);
                if (ol == l) {
                    ans++;
                    continue;
                }
                if (ol > l) {
                    ans++;
                    if (e.w > l - d[e.to]) {
                        int ol = d[i] + e.w - (l - d[e.to]);
                        if (ol > l) {
                            ans++;
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}