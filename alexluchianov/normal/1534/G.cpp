#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>
//#include <multiset>

using ll = long long;

int const nmax = 800000;

struct Point{
  int time;
  int y;
  bool operator < (Point oth) {
    if(time != oth.time)
      return time < oth.time;
    else
      return y < oth.y;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<Point> v;
  for(int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    v.push_back({x + y, y});
  }
  std::sort(v.begin(), v.end());
  int global = v[0].y, seg = v[0].y;
  ll result = 0;

  std::multiset<int> left, right;
  left.insert(global);
  right.insert(0);

  //std::cout << "set\n";
  //for(int i = 0; i < v.size(); i++)
  //  std::cout << v[i].time << " " << v[i].y << '\n';

  for(int i = 1; i < v.size(); i++) {
    seg += v[i].time - v[i - 1].time;
   
    if(v[i].y <= global) {
      left.insert(v[i].y);
      left.insert(v[i].y);
      left.erase(left.find(global));
      right.insert(global - seg);
      int newglobal = *left.rbegin();
      result += global - newglobal + std::fabs(newglobal - v[i].y);
      global = newglobal;
    } else if(global < v[i].y) {
      right.insert(v[i].y - seg);
      right.insert(v[i].y - seg);
      left.insert(*right.begin() + seg);
      int newglobal = *right.begin() + seg;
      result += std::fabs(newglobal - v[i].y);
      global = newglobal;
      right.erase(right.begin());
    }
  }
  std::cout << result << '\n';
  return 0;
}