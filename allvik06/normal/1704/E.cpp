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

using namespace std;
#define int long long
const int INF = 2e15;
const int mod = 998244353;

vector <vector <int>> g;
vector <int> ord, used;

void dfs(int v) {
    used[v] = 1;
    for (int i : g[v]) {
        if (!used[i]) dfs(i);
    }
    ord.push_back(v);
}

inline void solve1() {
    int n, m;
    cin >> n >> m;
    g.assign(n, {});
    used.assign(n, 0);
    ord.clear();
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) dfs(i);
    }
    int cnt = 0;
    while (cnt < n) {
        bool ok = false;
        for (int i : ord) {
            if (a[i]) {
                ok = true;
                --a[i];
                for (int j : g[i]) ++a[j];
            }
        }
        if (!ok) break;
        ++cnt;
    }
    reverse(ord.begin(), ord.end());
    for (int& i : a) i %= mod;
    for (int i : ord) {
        for (int j : g[i]) {
            a[j] = (a[j] + a[i]) % mod;
        }
    }
    cout << (a[ord.back()] + cnt) % mod << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        cin >> t;
        while (t--) {
            solve1();
        }
    } else {
        mt19937 rnd(228);
        int t;
        cin >> t;
        while (t--) {

        }
    }
}

/*

 */