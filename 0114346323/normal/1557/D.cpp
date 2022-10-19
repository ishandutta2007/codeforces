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
int n, m, a[600001], tot, pre[300001], dp[300001];
std::pair<int, int> t[4800001], tag[4800001];
bool vis[300001];
void Pushup(int x) { t[x] = std::max(t[x + x], t[x + x + 1]); }
void Pushdown(int x) {
  if (tag[x].first) {
    t[x + x] = t[x + x + 1] = tag[x + x] = tag[x + x + 1] = tag[x];
    tag[x] = {0, 0};
  }
}
void Modify(int L, int R, int l, int r, int v, int id, int x) {
  if (L <= l && r <= R) {
    t[x] = tag[x] = {v, id};
    return;
  }
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (L <= mid) Modify(L, R, l, mid, v, id, x + x);
  if (R > mid) Modify(L, R, mid + 1, r, v, id, x + x + 1);
  Pushup(x);
}
std::pair<int, int> Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return t[x];
  Pushdown(x);
  int mid = (l + r) >> 1;
  if (R <= mid) return Query(L, R, l, mid, x + x);
  if (L > mid) return Query(L, R, mid + 1, r, x + x + 1);
  std::pair<int, int> la = Query(L, R, l, mid, x + x),
                      ra = Query(L, R, mid + 1, r, x + x + 1);
  return std::max(la, ra);
}
std::vector<std::pair<int, int>> v[300001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, l, r;
    std::cin >> x >> l >> r;
    v[x].emplace_back(l, r);
    a[++tot] = l, a[++tot] = r;
  }
  std::sort(a + 1, a + tot + 1);
  int nn = std::unique(a + 1, a + tot + 1) - a - 1;
  for (int i = 1; i <= n; i++)
    for (auto &&[l, r] : v[i]) {
      l = std::lower_bound(a + 1, a + nn + 1, l) - a;
      r = std::lower_bound(a + 1, a + nn + 1, r) - a;
    }
  for (int i = 1; i <= n; i++) {
    std::pair<int, int> t;
    for (auto &&[l, r] : v[i]) checkmax(t, Query(l, r, 1, nn, 1));
    dp[i] = t.first + 1, pre[i] = t.second;
    for (auto &&[l, r] : v[i]) Modify(l, r, 1, nn, dp[i], i, 1);
  }
  int p = std::max_element(dp + 1, dp + n + 1) - dp, ans = 0;
  for (int i = p; i; i = pre[i]) vis[i] = true;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) ans++;
  std::cout << ans << '\n';
  for (int i = 1; i <= n; i++)
    if (!vis[i]) std::cout << i << ' ';
  return 0;
}