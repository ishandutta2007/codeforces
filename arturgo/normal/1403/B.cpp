#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
 
const int MAX = 5000;
const int MOD = 1e9 + 7;
 
struct Edge
{
    int node;
    int dist;
};
 
struct Node
{
    int parent;
    int val;
};
 
const int NOT_CALC = 1e9 + 42;
 
std::vector<int> path {};
std::vector<Edge> graph[MAX + 2];
Node dp[MAX + 2][MAX + 2];
 
Node calcDp(int node, int seen_before) {
   if(seen_before < 0) return {NOT_CALC, NOT_CALC};
    if (dp[node][seen_before].val != NOT_CALC) return dp[node][seen_before];
    
    
    for (Edge x: graph[node]) {
        int trans_val = calcDp(x.node, seen_before - 1).val + x.dist;
        trans_val = std::min(trans_val, NOT_CALC - 1);
        if (dp[node][seen_before].val > trans_val) {
            dp[node][seen_before].val = trans_val;
            dp[node][seen_before].parent = x.node;
        }
    }
    
    return dp[node][seen_before];
}
 
void print_path(int node, int seen_before) {
    path.push_back(node);
    if (node != 0) print_path(dp[node][seen_before].parent, seen_before - 1);
}
 
void solve() {
    int n, m, r, a, b, c, k, q, val, avg, t;
    int ans = 0;
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> t;
 
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b >> c;
        a--;
        b--;
        graph[b].push_back({a, c});
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j].val = NOT_CALC;
        }
    }
 
    dp[0][1].val = 0;
 
    for (int seen_before = 1; seen_before <= n; seen_before++) {
        val = calcDp(n - 1, seen_before).val;
 
        if (val <= t) {
            ans = std::max(ans, seen_before);
        }
    }
   
    std::cout << ans << '\n';
    print_path(n - 1, ans);
    path = {path.rbegin(), path.rend()};
    for (int& no: path) std::cout << no + 1 << ' ';
}
 
signed main() {
    bool multi = false;
    if (multi) {
        int t;
        std::cin >> t;
        for (int i = 0; i < t; i++) solve();
    } else {
        solve();
    }
}