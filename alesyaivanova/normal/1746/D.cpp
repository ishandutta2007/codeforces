#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
vector<int> g[maxn];
int p[maxn];
int s[maxn];
int dp[maxn][2];
int n, k;

void dfs(int v, int num) {
    if (g[v].empty()) {
        dp[v][0] = num * s[v];
        dp[v][1] = (num + 1) * s[v];
        return;
    }
    int sz = g[v].size();
    int new_num = num / sz;
    int sum = 0;
    vector<int> d;
    for (int to : g[v]) {
        dfs(to, new_num);
        sum += dp[to][0];
        d.pb(dp[to][1] - dp[to][0]);
    }
    sort(all(d));
    reverse(all(d));
    int r = num % sz;
    for (int i = 0; i < r; i++) {
        sum += d[i];
    }
    dp[v][0] = sum + num * s[v];
    dp[v][1] = sum + d[r] + (num + 1) * s[v];
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        g[p[i]].pb(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    dfs(0, k);
    cout << dp[0][0] << "\n";
    for (int i = 0; i < n; i++) {
        g[i] = {};
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}