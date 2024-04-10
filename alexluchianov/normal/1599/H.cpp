#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>

using ll = long long;

int const inf = 1000000000;

ll query(ll x, ll y) {
  std::cout << "? " << x << " " << y << std::endl;
  ll val;
  std::cin >> val;
  return val;
}

int main() {
  ll start = query(1, 1), stop = query(inf, 1), stopy = query(1, inf);
  ll x = 1;
  for(ll jump = (1 << 30); 0 < jump; jump /= 2)
    if(x + jump <= inf && query(x + jump, 1) == start - (x + jump - 1))
      x += jump;
  ll y = start - x + 2;
  std::cout << "! " << x << " " << y << " " << x + -(stop - inf + x - (y - 1)) << " " << y + -(stopy - inf + y - (x - 1)) << std::endl;
  return 0;
}