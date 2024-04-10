#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 25;
ll v[1 + nmax][1 + nmax];

void build(int n) { 
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++) {
      ll cost = (1LL<<(2 * n - i - j));
      if(j % 2 == 0)
        v[i][j] = cost;
      else
        v[i][j] = 0;
    }
}

void solve(int n) {
  ll number;
  std::cin >> number;
  int x = 1, y = 1;
  std::cout << x << " " << y << '\n';
  for(int i = 2 * n - 3;0 <= i; i--) {
    if((1LL << i) <= number) {
      number -= (1LL << i);
      if(y % 2 == 0) {
        x++;
      } else
        y++;
    } else {
      if(y % 2 == 0)
        y++;
      else
        x++;
    }
    std::cout << x << " " << y << '\n';
  }
  std::cout << std::flush;
}

int main() {
  int n;
  std::cin >> n;
  build(n);
  for(int i = 1;i <= n; i++) {
    for(int j = 1; j <= n; j++)
      std::cout << v[i][j] << " ";
    std::cout << '\n';
  }
  std::cout << std::flush;
  int q;
  std::cin >> q;
  for(int i = 1; i <= q; i++)
    solve(n);
  return 0;
}