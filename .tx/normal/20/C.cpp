#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

vector<pair<int, int> > g[111111];

int main() {
    sciid(n, m);
    for (int i = 0; i < m; ++i) {
        sciiid(x, y, z);
        --x; --y;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    vector<lint> d(n, 1LL << 60);
    vector<bool> used(n, false);
    priority_queue<pair<lint, int> > q;
    q.push({0, 0});
    d[0] = 0;
    vector<int> p(n, -1);
    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        int f = v.second;
        if (used[f]) {
            continue;
        }
        used[f] = true;
        for (auto& i : g[f]) {
            int to = i.first;
            int len = i.second;
            if (d[to] > d[f] + len) {
                d[to] = d[f] + len;
                q.push({-d[to], to});
                p[to] = f;
            }
        }
    }
    if (p[n - 1] == -1) {
        cout << -1;
        return 0;
    }
    vector<int> ans;
    int x = n - 1;
    while (x != -1) {
        ans.push_back(x);
        x = p[x];
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}