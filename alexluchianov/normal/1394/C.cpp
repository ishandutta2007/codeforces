#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 300000;
int const inf = 1000000000;

int eval(int n, std::vector<std::pair<int,int>> &v, int x, int y) {
  int result = 0;
  for(int i = 0; i < v.size(); i++) {
    result = std::max(result, std::abs(v[i].first - x));
    result = std::max(result, std::abs(v[i].second - y));
    result = std::max(result, std::abs(v[i].first - v[i].second - (x - y)));
  }
  return result;
}

void print2(int xtarget, int ytarget) {
  for(int i = 1;i <= xtarget; i++)
    std::cout << "B";
  for(int i = 1;i <= ytarget; i++)
    std::cout << "N";
  std::cout << '\n';

}

bool solve(int n, std::vector<std::pair<int,int>> &v, int dist, bool print) {
  int minx = 0, maxx = inf;
  int miny = 0, maxy = inf;
  int minxy = -inf, maxxy = inf;

  for(int i = 0; i < v.size(); i++) {
    int x = v[i].first;
    int y = v[i].second;
    minx = std::max(minx, x - dist);
    maxx = std::min(maxx, x + dist);
    miny = std::max(miny, y - dist);
    maxy = std::min(maxy, y + dist);

    minxy = std::max(minxy, x - y - dist);
    maxxy = std::min(maxxy, x - y + dist);
  }

  if(minx <= maxx && miny <= maxy && minxy <= maxxy) {
    if(print == 1) {
      int val = std::max(minxy, minx - maxy);
      int xtarget = std::max(minx, val + miny);
      int ytarget = xtarget - val;

      assert(0 <= xtarget && 0 <= ytarget);
      assert(eval(n, v, xtarget, ytarget) == dist);
      if(0 < xtarget || 0 < ytarget)
        print2(xtarget, ytarget);
      else {
        int smin = std::min(std::min(eval(n, v, 0, 1), eval(n, v, 1, 0)),
                            eval(n, v, 1, 1));
        if(smin == eval(n, v, 1, 0)) 
          print2(1, 0);
        else if(smin == eval(n, v, 0, 1))
          print2(0, 1);
        else
          print2(1, 1);
      }
    }
    return std::max(minxy, minx - maxy) <= 
      std::min(maxxy, maxx - miny);
  } else
    return false;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::vector<std::pair<int,int>> v;
  for(int i = 1;i <= n; i++) {
    std::string s;
    std::cin >> s;
    int x = 0, y = 0;
    for(int j = 0; j < s.size(); j++) {
      x += (s[j] == 'B');
      y += (s[j] == 'N');
    }
    v.push_back({x, y});
  }
  
  int result = 0;
  for(int jump = (1 << 20); 0 < jump; jump /= 2)
    if(solve(n, v, result + jump, 0) == 0)
      result += jump;
  if(solve(n, v, result, 0) == 0)
    result++;
  std::cout << result << '\n';
  solve(n, v, result, 1);
  return 0;
}