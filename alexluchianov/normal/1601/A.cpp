#include <iostream>
#include <vector>

using ll = long long;

int const sigma = 30;

void solve() {
  int n;
  std::cin >> n;
  int frec[sigma] = {0};
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    for(int j = 0; j < sigma; j++)
      frec[j] += (0 < ((1 << j) & val));
  }
  for(int i = 1; i <= n; i++)  {
    bool flag = true;
    for(int j = 0; j < sigma; j++) 
      flag &= ((frec[j] % i) == 0);
    if(flag == true)
      std::cout << i << " ";
  }
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}