#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n, m;
int col[200001];
namespace sat {
struct edge {
  int to, nxt;
} e[2000001];
int n, m, E, head[2000001], dfn[2000001], low[2000001], tot, s[2000001], top,
    col[2000001], c;
bool vis[2000001];
void checkmin(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
void add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  s[++top] = u;
  vis[u] = 1;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (!dfn[v]) {
      tarjan(v);
      checkmin(low[u], low[v]);
    } else {
      if (vis[v]) {
        checkmin(low[u], dfn[v]);
      }
    }
  }
  if (dfn[u] == low[u]) {
    c++;
    col[u] = c;
    vis[u] = 0;
    while (s[top] != u) {
      col[s[top]] = c;
      vis[s[top--]] = 0;
    }
    top--;
  }
}
void init(int nn) {
  n = nn / 2;
  E = 0, std::memset(head + 1, -1, 4 * nn);
  std::memset(dfn + 1, 0, 4 * nn);
  std::memset(low + 1, 0, 4 * nn);
  tot = 0;
  std::memset(vis + 1, 0, nn);
  std::memset(col + 1, 0, 4 * nn), c = 0;
}
bool Solve() {
  for (int i = 1; i <= 2 * n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= n; i++) {
    if (col[i] == col[i + n]) {
      return false;
    }
  }
  for (int i = 1; i <= n; i++) ::col[i] = col[i] > col[i + n];
  return true;
}
}  // namespace sat
struct Node {
  int u, v, w, c;
} e[200001];
std::vector<int> g[200001];
void Dfs(int u, int fe) {
  for (const auto &i : g[u]) {
    if (i == fe) continue;
    int v = u ^ e[i].u ^ e[i].v, w = e[i].w, c = e[i].c;
    if (w != -1) {
      if (c == 0) {
        sat::add(u, v), sat::add(v, u);
        sat::add(u + n, v + n), sat::add(v + n, u + n);
      }
      if (c == 1) {
        sat::add(u, v + n), sat::add(v + n, u);
        sat::add(u + n, v), sat::add(v, u + n);
      }
    }
    Dfs(v, i);
  }
}
void Dfs2(int u, int fe) {
  for (const auto &i : g[u]) {
    if (i == fe) continue;
    int v = u ^ e[i].u ^ e[i].v;
    if (e[i].w == -1) e[i].w = col[u] ^ col[v];
    Dfs2(v, i);
  }
}
void Solve() {
  std::cin >> n >> m;
  sat::init(2 * n);
  for (int i = 1; i < n; i++) {
    int u, v, w, c;
    std::cin >> u >> v >> w, c = w;
    if (w != -1) c = __builtin_popcount(c) & 1;
    e[i] = {u, v, w, c};
    g[u].push_back(i), g[v].push_back(i);
  }
  Dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    if (c == 0) {
      sat::add(u, v), sat::add(v, u);
      sat::add(u + n, v + n), sat::add(v + n, u + n);
    } else {
      sat::add(u, v + n), sat::add(v + n, u);
      sat::add(u + n, v), sat::add(v, u + n);
    }
  }
  std::memset(col + 1, 0, 4 * n);
  bool ok = sat::Solve();
  if (ok) {
    std::cout << "YES\n";
    Dfs2(1, 0);
    for (int i = 1; i < n; i++)
      std::cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';
  } else {
    std::cout << "NO\n";
  }
  for (int i = 1; i <= n; i++) std::vector<int>().swap(g[i]);
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}