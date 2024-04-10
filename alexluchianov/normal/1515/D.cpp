#include <iostream>
#include <vector>

using ll = long long;

void solve() {
  int n, l, r;
  std::cin >> n >> l >> r;
  std::vector<int> frec(1 + n, 0);
  for(int i = 1;i <= l; i++) {
    int val = 0;
    std::cin >> val;
    frec[val]++;
  }
  for(int i = 1;i <= r; i++) {
    int val;
    std::cin >> val;
    frec[val]--;
  }
  int sum = 0;
  for(int i = 1;i <= n; i++)
    sum += frec[i];
  if(sum < 0) {
    sum = -sum;
    for(int i = 1; i <= n; i++)
      frec[i] = -frec[i];
  }
  
  int result = 0;
  for(int i = 1;i <= n; i++) 
    if(0 < frec[i]) {
      int acc = std::min(sum / 2, frec[i] / 2);
      frec[i] -= acc * 2;
      sum -= acc * 2;
      result += acc;
    }

  int sum2 = 0;
  for(int i = 1;i <= n; i++)
    if(frec[i] < 0)
      sum2 -= frec[i];
  std::cout << result + sum + sum2 << '\n';
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