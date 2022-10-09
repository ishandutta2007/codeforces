#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int v[1 + nmax];

ll solve() {
  int n;
  std::cin >> n;
  int f[2] = {0, 0};
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    v[i] = v[i] % 2;
    f[v[i]]++;
  }

  ll result = 0, result2 = 0;
  if(f[1] < f[0]) {
    for(int i = 1;i <= n; i++)
      v[i] = !v[i];
    std::swap(f[0], f[1]);
  }
  
  if(f[0] == f[1]) { 
    f[0] = f[1] = 0;
    for(int i = 1;i <= n; i++) {
      f[v[i]]++;
      if(v[i] == 0) 
        result += std::fabs(f[1] - (f[0] - 1));
      else
        result2 += std::fabs((f[1] - 1) - f[0]);
    }
    return std::min(result, result2);
  } else if(f[0] + 1 == f[1]) {
    f[0] = f[1] = 0;
    for(int i = 1; i <= n; i++) {
      f[v[i]]++;
      if(v[i] == 1)
        result += std::fabs((f[1] - 1) - f[0]);
    }
    return result;
  } else
    return -1;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}