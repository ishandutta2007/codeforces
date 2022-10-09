#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 300000;

struct Point{
  int x;
  char ch;
} v[1 + nmax];

int solve(int n, int x, int y) {
  if(x == 0 || y == (n + 1)) {
    bool red = false, blue = false;
    int result = 0;
    int lastred = 0, lastblue = 0;
    for(int i = std::max(x, 1); i <= std::min(n, y); i++) {
      if(v[i].ch == 'G' || v[i].ch == 'R') {
        if(red == true) 
          result += v[i].x - lastred;
        lastred = v[i].x;
        red = true;
      }
      if(v[i].ch == 'G' || v[i].ch == 'B') {
        if(blue == true)
          result += v[i].x - lastblue;
        lastblue = v[i].x;
        blue = true;
      }
    }
    return result;
  } else {
    bool red = false, blue = false;
    int bigred = 0, bigblue = 0;
    int lastred = 0, lastblue = 0;
    for(int i = x; i <= std::min(n, y); i++) {
      if(v[i].ch == 'G' || v[i].ch == 'R') {
        if(red == true) 
          bigred = std::max(bigred, v[i].x - lastred);
        lastred = v[i].x;
        red = true;
      }
      if(v[i].ch == 'G' || v[i].ch == 'B') {
        if(blue == true)
          bigblue = std::max(bigblue, v[i].x - lastblue);
        lastblue = v[i].x;
        blue = true;
      }
    }
    return std::min(2 * (v[y].x - v[x].x), 3 * (v[y].x - v[x].x) - bigred - bigblue);
  }
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) 
    std::cin >> v[i].x >> v[i].ch;
  int result = 0;

  int last = 0;
  for(int i = 1; i <= n; i++) {
    if(v[i].ch == 'G') {
      result += solve(n, last, i);
      last = i;
    }
  }
  result += solve(n, last, n + 1);
  std::cout << result << '\n';
  return 0;
}