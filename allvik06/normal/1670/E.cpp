#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>

using namespace std;
#define int long long
vector <vector <pair <int, int>>> g;
vector <int> ansv, anse;
int now = 1, n;

void dfs(int v, int p, int cur) {
    for (auto i : g[v]) {
        if (i.first == p) continue;
        int ind = i.second;
        int to = i.first;
        if (cur == 0) {
            anse[ind] = n + now;
            ansv[to] = now;
        } else {
            anse[ind] = now;
            ansv[to] = n + now;
        }
        ++now;
        dfs(to, v, cur ^ 1);
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        now = 1;
        int p;
        cin >> p;
        n = (1 << p);
        g.assign(n, {});
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y; --x; --y;
            g[x].emplace_back(y, i);
            g[y].emplace_back(x, i);
        }
        ansv.assign(n, 0);
        anse.assign(n, 0);
        ansv[0] = n;
        dfs(0, -1, 0);
        cout << "1\n";
        for (int i = 0; i < n; ++i) cout << ansv[i] << " ";
        cout << "\n";
        for (int i = 0; i < n - 1; ++i) cout << anse[i] << " ";
        cout << "\n";
    }
    return 0;
}