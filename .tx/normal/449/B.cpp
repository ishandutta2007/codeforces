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

vector<pair<int, int> > g[111111];
bool used[111111];

int main() {
    sciiid(n, m, k);
    for (int i = 0; i < m; i++) {
        sciiid(x, y, z);
        --x; --y;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    int ans = 0;//
    vector<int> rw(n, -1);
    for (int i = 0; i < k; i++) {
        sciid(x, y);
        --x;
        if (rw[x] != -1) {
            ans++;
            rw[x] = min(rw[x], y);
        } else {
            rw[x] = y;
        }
    }

    vector<lint> d(n, 1e18);
    priority_queue<pair<lint, int> > q;
    d[0] = 0;
    q.push({0, 0});
    for (int i = 0; i < n; i++) {
        if (rw[i] != -1) {
            d[i] = rw[i];
            q.push({-d[i], i});
        }
    }
    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        int from = v.second;
        if (used[from]) {
            continue;
        }
        used[from] = true;
        for (auto& i : g[from]) {
            if (d[i.first] > d[from] + i.second) {
                d[i.first] = d[from] + i.second;
                q.push({-d[i.first], i.first});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (rw[i] == -1) {
            continue;
        }
        for (auto& v : g[i]) {
            if (d[i] == d[v.first] + v.second) {
                ans++;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}