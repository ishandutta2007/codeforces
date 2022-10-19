
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
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

using namespace std;
#define int long long
vector <vector <int>> g;
vector <int> cnt;
int k, ans = 0;

void dfs(int v, int p) {
    for (int i : g[v]) {
        if (i == p) continue;
        dfs(i, v);
        cnt[v] += cnt[i];
        ans += min(cnt[i], 2 * k - cnt[i]);
    }
}

void solve() {
    int n;
    cin >> n >> k;
    g.resize(n);
    cnt.resize(n);
    for (int i = 0; i < 2 * k; ++i) {
        int x;
        cin >> x;
        ++cnt[x - 1];
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    cout << ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
      //  cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*
=
 */