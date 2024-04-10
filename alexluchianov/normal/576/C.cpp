#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 1000;

struct Point{
  int x;
  int y;
  int id;
  bool operator < (Point a) {
    if(x / nmax != a.x / nmax)
      return x < a.x;
    else {
      if((x / nmax) % 2 == 0)
        return y < a.y;
      else
        return a.y < y;
    }
  }
};


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::vector<Point> v;  
  for(int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    v.push_back({x, y, i});
  }
  std::sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++)
    std::cout << v[i].id << " ";
  std::cout << '\n';
  return 0;
}