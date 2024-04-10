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
#define ll long long
vector <vector <int>> g;
vector <int> ans, used;

bool dfs(int v) {
    if (used[v]) return false;
    used[v] = 1;
    for (int i : g[v]) {
        if (ans[i] == -1) {
            ans[i] = v;
            return true;
        }
    }
    for (int i : g[v]) {
        if (dfs(ans[i])) {
            ans[i] = v;
            return true;
        }
    }
    return false;
}

void solve1() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> all;
    for (int i : a) {
        for (int j = 1; j <= n; ++j) {
            all.push_back(i * j);
        }
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    map <int, int> d;
    int ln = (int)all.size();
    for (int i = 0; i < ln; ++i) d[all[i]] = i;
    g.resize(ln);
    ans.resize(n, -1);
    used.resize(ln);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[d[a[i] * j]].push_back(i);
        }
    }
    ll res = 0;
    for (int i = 0; i < ln; ++i) {
        if (dfs(i)) {
            res += all[i];
            used.assign(ln, 0);
        }
    }
    cout << res;
}


signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */