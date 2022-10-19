#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;
#define int long long
const int mod = 1e9 + 7;
vector <int> fact, rfact;

int power(int a, int x) {
    if (x == 0) return 1;
    if (x & 1) return a * power(a, x - 1) % mod;
    else return power(a * a % mod, x >> 1);
}

inline void build_fact(int n) {
    fact.resize(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    rfact.resize(n + 1, 1);
    rfact[n] = power(fact[n], mod - 2);
    for (int i = n - 1; i > 1; --i) {
        rfact[i] = (rfact[i + 1] * (i + 1)) % mod;
    }
}

inline int cnk(int n, int k) {
    if (n < k) return 0;
    return (fact[n] * rfact[k] % mod) * rfact[n - k] % mod;
}

int n, k, ans = 0;
vector <vector <int>> g;
vector <int> sz, dp;

void dfs1(int v, int p) {
    sz[v] = 1;
    for (int i : g[v]) {
        if (i == p) continue;
        dfs1(i, v);
        sz[v] += sz[i];
    }
    int cnt = cnk(sz[v], k);
    for (int i : g[v]) {
        if (i == p) continue;
        dp[v] = (dp[v] + dp[i]) % mod;
        cnt = (cnt - cnk(sz[i], k) + mod) % mod;
    }
    dp[v] = (dp[v] + cnt * sz[v]) % mod;
}

void dfs2(int v, int p, int val) {
    int cnt = cnk(n, k);
    for (int i : g[v]) {
        if (i == p) cnt = (cnt - cnk(n - sz[v], k) + mod) % mod;
        else {
            cnt = (cnt - cnk(sz[i], k) + mod) % mod;
            val = (val + dp[i]) % mod;
        }
    }
    ans = (ans + val + cnt * n) % mod;
    cnt = (cnt - cnk(n, k) + mod) % mod;
    for (int i : g[v]) {
        if (i == p) continue;
        int new_cnt = cnt;
        new_cnt = (new_cnt + cnk(n - sz[i], k) + cnk(sz[i], k)) % mod;
        dfs2(i, v, (val - dp[i] + new_cnt * (n - sz[i]) + mod) % mod);
    }
}

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    cin >> n >> k;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    build_fact(n);
    sz.resize(n);
    dp.resize(n);
    dfs1(0, -1);
    dfs2(0, -1, 0);
    cout << ans;
}

/*

 */