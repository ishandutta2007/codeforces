#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 100000;
int v[1 + nmax][2];

int main() {
  int n;
  ll m;
  std::cin >> n >> m;
  m = m % (2 * n);
  ll startx, starty;
  std::cin >> startx >> starty;
  for(int i = 0; i < n; i++)
    std::cin >> v[i][0] >> v[i][1];
  for(int i = 1; i <= m; i++) {
    int ptr = (i - 1) % n;
    startx = 2 * v[ptr][0] - startx;
    starty = 2 * v[ptr][1] - starty;
  }
  std::cout << startx << " " << starty << '\n';

  return 0;
}