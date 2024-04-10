#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 1000;
int const inf = 1000000000;

ll v[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  ll result = 0;
  for(int i = 1;i < n; i += 2) {
    ll acc = 0, smin = inf;
    for(int j = i; j <= n; j++) {
      if(smin < 0)
        break;
      if(j % 2 == 1) {
        acc += v[j];
      } else {
        ll delta = acc - v[j];
        if(0 < delta) {
          result += std::max(0LL, std::min(std::min(v[i], smin + 1) - delta, v[j]));
        } else {
          result += std::max(0LL, std::min(std::min(v[i], smin + 1), v[j] + delta));  
        }
        acc -= v[j];
      }
      smin = std::min(smin, acc);
    }
  }
  std::cout << result << '\n';
  return 0;
}