#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve() {
  int lim1, lim2;
  std::cin >> lim1 >> lim2;
  int cnt1, cnt2;
  int w1, w2;
  std::cin >> cnt1 >> cnt2;
  std::cin >> w1 >> w2;
  if(w2 < w1) {
    std::swap(w1, w2);
    std::swap(cnt1, cnt2);
  }
  int result = 0;
  for(int i = 0; i <= cnt1 && i * w1 <= lim1; i++) {
    int oth = std::min((cnt1 - i), lim2 / w1);
    result = std::max(result, i + oth + std::min((lim1 - i * w1) / w2 + (lim2 - oth * w1) / w2, cnt2));
  }
  std::cout << result << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
}