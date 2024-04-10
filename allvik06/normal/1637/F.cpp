#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <iomanip>
#include <array>
#include <deque>
#include <cmath>
#include <complex>
#include <queue>
#include <iomanip>

using namespace std;
#define int long long

const int INF = 1e9;
vector <int> h, mx;
vector <vector <int>> g;
int ans = 0;

void dfs(int v, int p) {
    for (int i : g[v]) {
        if (i == p) continue;
        dfs(i, v);
        mx[v] = max(mx[v], mx[i]);
    }
    ans += max(0LL, h[v] - mx[v]);
    mx[v] = max(mx[v], h[v]);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    int root = max_element(h.begin(), h.end()) - h.begin();
    mx.resize(n);
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int mx1 = 0, mx2 = 0;
    for (int i : g[root]) {
        dfs(i, root);
        if (mx[i] > mx1) {
            mx2 = mx1;
            mx1 = mx[i];
        } else if (mx[i] > mx2) {
            mx2 = mx[i];
        }
    }
    cout << ans + h[root] * 2 - mx1 - mx2;
}

/*

 */