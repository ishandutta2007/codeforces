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
template <class T, typename = decltype(std::declval<T>().begin()),
          typename = decltype(std::declval<T>().end()),
          typename = typename std::enable_if<!std::is_base_of<
              std::string, typename std::decay<T>::type>::value>::type,
          typename value_type = typename T::value_type>
std::ostream &operator<<(std::ostream &out, const T &container) {
  for (auto it = container.begin(); it != container.end(); ++it)
    out << *it << ' ';
  return out;
}
std::ostream &operator<<(std::ostream &out, __int128_t x) {
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
struct Node {
  int a, b, id;
} a[100001];
struct Edge {
  int to, nxt;
} e[200001];
int T, n, E, head[100001], dfn[100001], low[100001], tot, col[100001], c,
    s[100001], top, deg[100001];
bool vis[100001];
void Add(int f, int t) { e[E] = {t, head[f]}, head[f] = E++; }
void Tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  s[++top] = u, vis[u] = true;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (!dfn[v])
      Tarjan(v), checkmin(low[u], low[v]);
    else if (vis[v])
      checkmin(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    c++;
    while (s[top] != u) col[s[top]] = c, vis[s[top--]] = false;
    col[u] = c, vis[u] = false, top--;
  }
}
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i].a, a[i].id = i;
  for (int i = 1; i <= n; i++) std::cin >> a[i].b;
  std::memset(dfn + 1, 0, 4 * n);
  std::memset(low + 1, 0, 4 * n);
  tot = 0;
  std::memset(col + 1, 0, 4 * n), c = 0;
  E = 0, std::memset(head + 1, -1, 4 * n);
  std::memset(deg + 1, 0, 4 * n);
  std::sort(a + 1, a + n + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.a < rhs.a; });
  for (int i = 2; i <= n; i++) Add(a[i].id, a[i - 1].id);
  std::sort(a + 1, a + n + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.b < rhs.b; });
  for (int i = 2; i <= n; i++) Add(a[i].id, a[i - 1].id);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) Tarjan(i);
  for (int i = 1; i <= n; i++)
    for (int j = head[i]; j != -1; j = e[j].nxt) {
      int v = e[j].to;
      if (col[i] != col[v]) deg[col[v]]++;
    }
  for (int i = 1; i <= n; i++) std::cout << (deg[col[i]] == 0);
  std::cout << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}