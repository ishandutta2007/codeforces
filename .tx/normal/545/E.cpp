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

using namespace std;

struct edge {
    int to, len, id;
};

vector<edge> g[333333];

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciiid(x, y, z);
        --x; --y;
        g[x].push_back({y, z, i});
        g[y].push_back({x, z, i});
    }
    scid(s);
    --s;
    vector<lint> d(n, 1e18);
    vector<int> p(n, -1);
    vector<int> c(n, 0);
    d[s] = 0;
    priority_queue<pair<lint, int> > q;
    q.push({0, s});
    vector<bool> done(n, false);
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int v = it.second;
        if (done[v]) {
            continue;
        }
        done[v] = true;
        for (auto i : g[v]) {
            if (d[i.to] > d[v] + i.len || (d[i.to] == d[v] + i.len && c[i.to] > i.len)) {
                d[i.to] = d[v] + i.len;
                p[i.to] = i.id;
                c[i.to] = i.len;
                q.push({-d[i.to], i.to});
            }
        }
    }
    lint sum = 0;
    for (int i : c) {
        sum += i;
    }
    cout << sum << "\n";
    for (int i : p) {
        if (i != -1) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}