#include <bits/stdc++.h>

#include <iostream>
#include <set>
#include <vector>

using namespace std;
const int N = 3e5 + 10;
const int64_t INF = 1e18;
int U[N], V[N], W[N], vis[N], par[N];
bool included[N];
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
  int start;
  scanf("%d", &start);
  d[start] = 0;
  set<pair<pair<int64_t, int>, pair<int, int>>> S;
  S.insert({{d[start], 0}, {start, 0}});
  int64_t sum = 0;
  while (!S.empty()) {
    auto it = *S.begin();
    S.erase(S.begin());
    int x = it.second.first;
    int pe = it.second.second;
    if (vis[x]) continue;
    par[x] = pe;
    sum += W[pe];
    vis[x] = 1;
    for (auto e : g[x]) {
      int y = adj(x, e);
      if (d[x] + W[e] <= d[y]) {
        d[y] = d[x] + W[e];
        S.insert({{d[y], W[e]}, {y, e}});
      }
    }
  }
  printf("%lld\n", sum);
  for (int i = 1; i <= n; i++)
    if (i != start) printf("%d ", par[i]);
}