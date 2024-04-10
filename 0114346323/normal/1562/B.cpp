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
int T, n;
bool np[101];
std::string s;
void Init() {
  np[1] = true;
  for (int i = 2; i <= 100; i++)
    if (!np[i])
      for (int j = i * i; j <= 100; j += i) np[j] = true;
}
void Solve() {
  std::cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int x = s[i] - '0';
    if (np[x]) {
      std::cout << "1\n" << x << '\n';
      return;
    }
  }
  for (int i = 0; i + 1 < n; i++)
    for (int j = i + 1; j < n; j++) {
      int x = (s[i] - '0') * 10 + s[j] - '0';
      if (np[x]) {
        std::cout << "2\n" << x << '\n';
        return;
      }
    }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init();
  std::cin >> T;
  while (T--) Solve();
  return 0;
}