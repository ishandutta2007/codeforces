#include <bits/stdc++.h>

#include <iostream>
#include <set>
#include <vector>

using namespace std;
const int N = 3e5 + 10;
const int64_t INF = 1e18;
int U[N], V[N], W[N], vis[N], par[N];
int64_t d[N];
vector<int> g[N];
int adj(int x, int e) { return U[e] ^ V[e] ^ x; }
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", U + i, V + i, W + i);
    g[U[i]].push_back(i);
    g[V[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) d[i] = INF;
  int start = 1;
  d[start] = 0;
  set<pair<int64_t, int>> S;
  S.insert({d[start], start});
  while (!S.empty()) {
    auto it = *S.begin();
    S.erase(S.begin());
    int x = it.second;
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto e : g[x]) {
      int y = adj(x, e);
      if (d[x] + W[e] < d[y]) {
        auto it = S.find({d[y], y});
        if (it != S.end()) {
          S.erase({d[y], y});
        }
        par[y] = x;
        d[y] = d[x] + W[e];
        S.insert({d[y], y});
      }
    }
  }
  if (d[n] == INF) {
    puts("-1");
  } else {
    vector<int> ans;
    for (int i = n; i != 0; i = par[i]) {
      ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) {
      printf("%d ", i);
    }
  }
}