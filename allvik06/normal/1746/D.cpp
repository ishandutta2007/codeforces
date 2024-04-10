#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
#define int long long
vector <vector <int>> g;
vector <int> minv, maxv, s;

void dfs(int v) {
    int c = (int)g[v].size();
    for (int i : g[v]) {
        minv[i] = minv[v] / c;
        maxv[i] = (maxv[v] + c - 1) / c;
        dfs(i);
    }
}

vector <int> dp_min, dp_max;

void calc_dp(int v) {
    int sum = 0, cnt = 0;
    vector <int> pl;
    for (int i : g[v]) {
        calc_dp(i);
        sum += dp_min[i];
        cnt += minv[i];
        if (minv[i] != maxv[i]) pl.push_back(dp_max[i] - dp_min[i]);
    }
    sort(pl.rbegin(), pl.rend());
    dp_min[v] = sum + minv[v] * s[v];
    dp_max[v] = sum + maxv[v] * s[v];
    for (int i = 0; i < (int)pl.size(); ++i) {
        if (i < minv[v] - cnt) dp_min[v] += pl[i];
        if (i < maxv[v] - cnt) dp_max[v] += pl[i];
    }
}

inline void solve() {
    int n, k;
    cin >> n >> k;
    g.assign(n, {});
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        g[x - 1].push_back(i);
    }
    s.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> s[i];
    minv.assign(n, 0);
    maxv.assign(n, 0);
    minv[0] = maxv[0] = k;
    dfs(0);
    dp_min.assign(n, 0);
    dp_max.assign(n, 0);
    calc_dp(0);
    cout << dp_max[0] << "\n";
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */