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
struct Node {
  int len, l, llen, r, rlen;
  long long ans;
} t[800001];
int n, q, a[200001];
auto calc = [](int x) { return x * static_cast<long long>(x + 1) >> 1; };
Node Merge(const Node &lhs, const Node &rhs) {
  Node ans;
  ans.len = lhs.len + rhs.len;
  ans.l = lhs.l, ans.r = rhs.r;
  ans.ans = lhs.ans + rhs.ans;
  ans.llen = lhs.llen, ans.rlen = rhs.rlen;
  if (lhs.r <= rhs.l) {
    ans.ans -= calc(lhs.rlen) + calc(rhs.llen);
    ans.ans += calc(lhs.rlen + rhs.llen);
    if (lhs.llen == lhs.len) ans.llen += rhs.llen;
    if (rhs.rlen == rhs.len) ans.rlen += lhs.rlen;
  }
  return ans;
}
void Pushup(int x) { t[x] = Merge(t[x + x], t[x + x + 1]); }
void Build(int l, int r, int x) {
  if (l == r) {
    t[x].len = t[x].llen = t[x].rlen = 1;
    t[x].l = t[x].r = a[l];
    t[x].ans = 1LL;
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int l, int r, int p, int v, int x) {
  if (l == r) {
    t[x].l = t[x].r = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    Modify(l, mid, p, v, x + x);
  else
    Modify(mid + 1, r, p, v, x + x + 1);
  Pushup(x);
}
Node Query(int L, int R, int l, int r, int x) {
  if (L <= l && r <= R) return t[x];
  int mid = (l + r) >> 1;
  if (R <= mid)
    return Query(L, R, l, mid, x + x);
  else if (L > mid)
    return Query(L, R, mid + 1, r, x + x + 1);
  else
    return Merge(Query(L, R, l, mid, x + x),
                 Query(L, R, mid + 1, r, x + x + 1));
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  Build(1, n, 1);
  while (q--) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1)
      Modify(1, n, x, y, 1);
    else
      std::cout << Query(x, y, 1, n, 1).ans << '\n';
  }
  return 0;
}