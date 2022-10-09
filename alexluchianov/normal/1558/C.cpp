#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 2021;
int v[1 + nmax];

std::vector<int> sol;

bool makemove(int n, int p) {
  if(1 <= p && p <= n && p % 2 == 1) {
    sol.push_back(p);
    std::reverse(v + 1, v + p + 1);
    return 1;
  } else
    return 0;
}

void solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];

  sol.clear();
  for(int i = n; 1 < i; i -= 2) {
    int pos = 0;
    for(int j = 1;j <= n; j++)
      if(v[j] == i)
        pos = j;
    if(makemove(n, pos) == 0) {
      std::cout << -1 << '\n';
      return ;
    }
    pos = 0;
    for(int j = 1;j <= n; j++)
      if(v[j] == i - 1)
        pos = j;
    if(makemove(n, pos - 1) == 0) {
      std::cout << -1 << '\n';
      return ;
    }
    if(makemove(n, pos + 1) == 0) {
      std::cout << -1 << '\n';
      return ;
    }
    if(makemove(n, 3) == 0) {
      std::cout << -1 << '\n';
      return ;
    }
    if(makemove(n, i) == 0) {
      std::cout << -1 << '\n';
      return ;
    }
  }

  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}