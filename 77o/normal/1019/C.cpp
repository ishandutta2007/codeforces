#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <map>
#include <random>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            (res *= a) %= MOD;
        p >>= 1;
        (a *= a) %= MOD;
    }
    return res;
}

mt19937 rng(123);

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector(0, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<int> color(n + 1);
    vector<int> order;
    for (int i = 1; i <= n; i++) {
        if (color[i])
            continue;
        color[i] = 1;
        order.push_back(i);
        for (int u : g[i])
            color[u] = 1;
    }
    reverse(order.begin(), order.end());
    for (int i : order) {
        if (color[i] == 1) {
            color[i] = 2;
            for (int u : g[i])
                color[u] = 0;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (color[i] == 2)
            ans.push_back(i);
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}