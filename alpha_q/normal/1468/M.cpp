#include <bits/stdc++.h>

using namespace std;

const int B = 369;
const int N = 400010;

bitset <N> vis;
vector <int> g[N];
int t, n, where[N];
vector <pair <int, int>> to[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    map <int, int> id;
    int ptr = 0;
    for (int i = 1, sz; i <= n; ++i) {
      scanf("%d", &sz);
      while (sz--) {
        int x; scanf("%d", &x);
        if (id.find(x) == id.end()) id[x] = ++ptr;
        x = id[x];
        g[i].emplace_back(x);
      }
    }
    int ans_i = -1, ans_j = -1;
    for (int i = 1; i <= n; ++i) {
      if (g[i].size() < B) continue;
      for (int x : g[i]) vis[x] = 1;
      for (int j = 1; j <= n; ++j) {
        if (j <= i and g[j].size() >= B) continue;
        int match = 0;
        for (int x : g[j]) {
          if (vis[x]) ++match;
          if (match == 2) {
            ans_i = i, ans_j = j;
            break;
          }
        }
        if (~ans_i) break;
      }
      for (int x : g[i]) vis[x] = 0;
      if (~ans_i) break;
    }
    if (ans_i == -1) {
      for (int i = 1; i <= n; ++i) {
        if (g[i].size() >= B) continue;
        for (int j : g[i]) for (int k : g[i]) if (j < k) {
          to[j].emplace_back(k, i);
        }
      }
      for (int i = 1; i <= ptr; ++i) {
        for (auto it : to[i]) {
          if (where[it.first]) {
            ans_i = it.second, ans_j = where[it.first];
            break;
          }
          where[it.first] = it.second;
        }
        for (auto it : to[i]) where[it.first] = 0;
        if (~ans_i) break;
      }
    }
    if (~ans_i) printf("%d %d\n", ans_i, ans_j);
    else puts("-1");
    for (int i = 1; i <= max(n, ptr); ++i) g[i].clear(), to[i].clear(), vis[i] = where[i] = 0;
  }
  return 0;
}