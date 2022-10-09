#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int v[5 + nmax];
char who[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, c, d;
  std::cin >> n >> c >> d;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i] >> who[i];
  std::cin >> v[n + 1];
  int last1 = v[n + 1], last2 = v[n + 1];
  ll result = 1LL * n * d, base = 0;

  for(int i = n; 1 <= i; i--) {
    if(i < n && who[i] == who[i + 1]) {
      if(who[i + 1] == 'W')
        base += std::min(1LL * d, 1LL * c * (last2 - v[i + 1]));
      else
        base += std::min(1LL * d, 1LL * c * (last1 - v[i + 1]));
    }
    if(who[i] == 'W')
      last1 = v[i];
    else
      last2 = v[i];
    result = std::min(result, 1LL * (i - 1) * d + 1LL * c * (v[n + 1] - v[i]) + base);
  }

  std::cout << result << '\n';
  return 0;
}