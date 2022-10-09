#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve() {
  int n;
  ll total;
  std::cin >> n >> total;
  std::vector<int> sol;
  ll curr = 0;
  std::vector<int> v(1 + n);
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++) {
    int val = v[i];
    if(total < val)
      continue;
    if((total + 1) / 2 <= val) {
      std::cout << 1 << '\n' << i << '\n';
      return ;
    } else {
      curr += val;
      sol.push_back(i);
      if((total + 1) / 2 <= curr)
        break;
    }
  }

  if((total + 1) / 2 <= curr) {
    std::cout << sol.size() << '\n';
    for(int i = 0; i < sol.size(); i++)
      std::cout << sol[i] << " ";
    std::cout << '\n';
  } else
    std::cout << -1 << '\n';
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