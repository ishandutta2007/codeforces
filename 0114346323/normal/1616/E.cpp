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
  if (!x) return out << 0;
  static int s[101], top;
  top = 0;
  while (x) s[top++] = x % 10, x /= 10;
  for (int i = top - 1; i >= 0; i--) out << s[i];
  return out;
}
int T, n;
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n) { Clear(); }
  void Init(int n) { n_ = n, Clear(); }
  void Add(int x, const T &v) {
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  T Query(int x) {
    T s(0);
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  void Clear() { std::memset(t_ + 1, 0, sizeof(T) * n_); }
  ~FenwickTree() {}

 private:
  int n_;
  T t_[200001];
};
void Solve() {
  std::string s, t, tmp;
  std::cin >> n >> s >> t;
  tmp = s;
  std::sort(tmp.begin(), tmp.end());
  if (tmp >= t) {
    std::cout << "-1\n";
    return;
  }
  std::vector<int> pos[26];
  s = ' ' + s, t = ' ' + t;
  for (int i = n; i >= 1; i--) pos[s[i] - 'a'].push_back(i);
  long long ans = 0x3f3f3f3f3f3f3f3fLL, now = 0LL;
  FenwickTree bit(n);
  for (int i = 1; i <= n; i++) {
    int min = n + 1;
    for (int j = 0; j < t[i] - 'a'; j++) {
      if (!pos[j].empty())
        checkmin(min, pos[j].back() + bit.Query(pos[j].back()));
    }
    if (min != n + 1) checkmin(ans, now + min - i);
    int u = t[i] - 'a';
    if (pos[u].empty()) break;
    now += pos[u].back() + bit.Query(pos[u].back()) - i;
    bit.Add(1, 1), bit.Add(pos[u].back() + 1, -1);
    pos[u].pop_back();
  }
  std::cout << ans << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}