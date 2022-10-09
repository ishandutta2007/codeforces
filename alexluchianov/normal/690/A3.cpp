#include <iostream>

void solve() {
  int n, pos;
  std::cin >> n >> pos;
  int sum = 0;
  for(int i = 1;i < n; i++) {
    int val;
    std::cin >> val;
    sum += val;
  }
  sum = sum % n;
  pos -= sum;
  if(pos <= 0)
    pos += n;
  std::cout << pos  << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}