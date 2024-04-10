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
int T, s, n, pw[10];
void Solve() {
  std::cin >> s >> n;
  if (n == 1) {
    std::cout << s << '\n';
    return;
  }
  std::multiset<int> st;
  int tmp = s % 10;
  for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= (s / pw[i]) % 10; j++) st.emplace(pw[i]);
  while (static_cast<int>(st.size()) + tmp < n) {
    int x = *st.begin();
    st.erase(st.begin());
    if (x == 10)
      tmp += x;
    else
      for (int i = 1; i <= 10; i++) st.emplace(x / 10);
  }
  for (int i = 1; i <= tmp; i++) st.emplace(1);
  while (static_cast<int>(st.size()) > n) {
    auto i = std::prev(--st.end()), j = --st.end();
    int x = *i, y = *j, z = x + y;
    st.erase(st.find(x)), st.erase(st.find(y));
    st.emplace(z);
  }
  for (auto &&x : st) std::cout << x << ' ';
  std::cout << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  pw[0] = 1;
  for (int i = 1; i <= 9; i++) pw[i] = pw[i - 1] * 10;
  std::cin >> T;
  while (T--) Solve();
  return 0;
}