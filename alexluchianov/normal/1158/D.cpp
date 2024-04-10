#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 2000;
struct Point{
  int x;
  int y;
  int id;
  bool operator < (Point const oth) const{
    if(x != oth.x)
      return x < oth.x;
    else
      return y < oth.y;
  }
};
Point orig;

ll det3(Point a, Point b, Point c) {
  ll splus = 1LL * a.x * b.y + 1LL * a.y * c.x + 1LL * b.x * c.y;
  ll sminus = 1LL * a.x * c.y + 1LL * a.y * b.x + 1LL * b.y * c.x;
  return splus - sminus;
}

bool compare(Point a, Point b) {
  return 0 < det3(orig, a, b);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Point> v;
  for(int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    v.push_back({x, y, i});
  }
  std::sort(v.begin(), v.end());
  int step = 0;
  while(1 < v.size()) {
    std::cout << v[0].id << '\n';
    orig = v[0];
    v.erase(v.begin());
    if(1 < v.size()) {
      char val;
      std::cin >> val;
      std::sort(v.begin(), v.end(), compare);
      if(val == 'R')
        std::reverse(v.begin(), v.end());
    }
  }
  std::cout << v[0].id << '\n';
  return 0;
}