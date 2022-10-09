#include <iostream>
#include <vector>

int const sigma = 10;

void solve() {
  int n;
  std::cin >> n;
  int frec[1 + sigma] = {0};
  for(int i = 1;i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    frec[y] = std::max(frec[y], x);
  }
  int result = 0;
  for(int i = 1;i <= sigma; i++)
    if(0 == frec[i]) {
      std::cout << "MOREPROBLEMS\n";
      return ;
    } else
      result += frec[i];
  std::cout << result << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    solve();
  }
  return 0;
}