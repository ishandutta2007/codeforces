#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
}

int n;
vector<vector<int>> G;
vector<int> s;

#define pii pair<long long, long long>

bool cmp(pii a, pii b) {
    return a.second - a.first > b.second - b.first;
}

pii solve(int v, int x) {
    // cout << v << ' ' << x << endl;
    int ch = G[v].size();
    if (ch == 0) return {s[v] * x, s[v] * (x + 1)};
    int low = x / ch;
    vector<pii> profits(ch);
    for (int i = 0; i < ch; ++i)
        profits[i] = solve(G[v][i], low);

    sort(profits.begin(), profits.end(), cmp);
    
    int ans1 = s[v] * x;
    int big = x % ch;
    for (int i = 0; i < ch; ++i)
        ans1 += i < big ? profits[i].second : profits[i].first;

    int ans2 = s[v] * (x + 1);
    big = (x + 1) % ch;
    if (big == 0)
        big = ch;
    for (int i = 0; i < ch; ++i)
        ans2 += i < big ? profits[i].second : profits[i].first;
    
    // cout << v << ' ' << x << ' ' << ans1 << ' ' << ans2 << endl;
    return {ans1, ans2};
}

void solve() {
    int n, k;
    cin >> n >> k;
    G = vector<vector<int>> (n);
    s = vector<int> (n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        G[x - 1].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    cout << solve(0, k).first << "\n";
}


signed main() {
    initIO();
    
    int t;
    cin >> t;
    while (t--)
        solve();
}