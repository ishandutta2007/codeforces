// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
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
  if (!x) return out << 0;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n, a[250001], pre_gt[250001], pre_le[250001], s[250001], top, f[250001];
class Sgt {
 public:
  void Build(int l, int r, int x) {
    min_[x] = 0x3f3f3f3f;
    if (l == r) return;
    int mid = (l + r) >> 1;
    Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  }
  void Modify(int l, int r, int p, int v, int x) {
    if (l == r) {
      min_[x] = v;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      Modify(l, mid, p, v, x + x);
    else
      Modify(mid + 1, r, p, v, x + x + 1);
    Pushup(x);
  }
  int Query(int L, int R, int l, int r, int x) {
    if (L <= l && r <= R) return min_[x];
    int mid = (l + r) >> 1, ans = 0x3f3f3f3f;
    if (L <= mid) checkmin(ans, Query(L, R, l, mid, x + x));
    if (R > mid) checkmin(ans, Query(L, R, mid + 1, r, x + x + 1));
    return ans;
  }

 private:
  int min_[1000001];
  void Pushup(int x) { min_[x] = std::min(min_[x + x], min_[x + x + 1]); }
} sgt1, sgt2;
int s1[250001], top1, s2[250001], top2;
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::fill(s + 1, s + n + 1, 0), top = 0;
  for (int i = 1; i <= n; i++) {
    while (top && a[s[top]] < a[i]) top--;
    pre_gt[i] = s[top];
    s[++top] = i;
  }
  std::fill(s + 1, s + n + 1, 0), top = 0;
  for (int i = 1; i <= n; i++) {
    while (top && a[s[top]] > a[i]) top--;
    pre_le[i] = s[top];
    s[++top] = i;
  }
  std::fill(f + 2, f + n + 1, 0x3f3f3f3f);
  std::fill(s1 + 1, s1 + n + 1, 0), top1 = 0;
  std::fill(s2 + 1, s2 + n + 1, 0), top2 = 0;
  sgt1.Build(1, n, 1), sgt2.Build(1, n, 1);
  s1[++top1] = 1, sgt1.Modify(1, n, 1, 0, 1);
  s2[++top2] = 1, sgt2.Modify(1, n, 1, 0, 1);
  for (int i = 2; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      int p = std::upper_bound(s1 + 1, s1 + top1 + 1, pre_gt[i]) - s1;
      f[i] = sgt1.Query(p, top1, 1, n, 1) + 1;
      while (top2 && a[s2[top2]] < a[i])
        sgt2.Modify(1, n, top2, 0x3f3f3f3f, 1), top2--;
      s1[++top1] = i, sgt1.Modify(1, n, top1, f[i], 1);
      s2[++top2] = i, sgt2.Modify(1, n, top2, f[i], 1);
    } else {
      int p = std::upper_bound(s2 + 1, s2 + top2 + 1, pre_le[i]) - s2;
      f[i] = sgt2.Query(p, top2, 1, n, 1) + 1;
      while (top1 && a[s1[top1]] > a[i])
        sgt1.Modify(1, n, top1, 0x3f3f3f3f, 1), top1--;
      s1[++top1] = i, sgt1.Modify(1, n, top1, f[i], 1);
      s2[++top2] = i, sgt2.Modify(1, n, top2, f[i], 1);
    }
  }
  // for (int i = 1; i <= n; i++) std::cerr << f[i] << " \n"[i == n];
  std::cout << f[n] << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}