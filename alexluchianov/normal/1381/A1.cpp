#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
char v[1 + nmax], v2[1 + nmax];

void solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++){
    std::cin >> v[i];
    v[i] -= '0';
  }

  for(int i = 1;i <= n; i++) {
    std::cin >> v2[i];
    v2[i] -= '0';
  }

  bool lazy = 0;
  int x = n, y = 1, sign = -1, xup = 0;
  std::vector<int> sol;
  for(int i = n; 1 <= i; i--) {
    if(v2[i] == v[x] ^ xup) 
      x += sign;
    else if(v2[i] == v[y] ^ xup ^ 1) {
      std::swap(x, y);
      sign *= -1;
      x += sign;
      xup ^= 1;
      sol.push_back(i);
    } else {
      sol.push_back(1);
      std::swap(x, y);

      sign *= -1;
      x += sign;
      xup ^= 1;
      sol.push_back(i);
    }
  }
  std::cout << sol.size() << " ";
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';
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