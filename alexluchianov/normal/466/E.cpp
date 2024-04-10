#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int const lgmax = 20;
int far[1 + lgmax][1 + nmax];
int mult[1 + nmax], multp[1 + nmax];
int start[1 + nmax], height[1 + nmax];

void jump(int gala) {
  if(mult[gala] != gala) {
    jump(mult[gala]);
    multp[gala] = multp[gala] + multp[mult[gala]];
    mult[gala] = mult[mult[gala]];
  }
}

int getlevel(int node) {
  jump(node);
  return multp[node];
}

int extract(int h, int node) {
  if(far[h][node] == 0) {
    int to = extract(h - 1, node);
    far[h][node] = extract(h - 1, to);
  }
  return far[h][node];
}

int raise(int node, int target) {
  for(int h = lgmax; 0 <= h; h--)
    if((1 << h) <= target) {
      target -= (1 << h);
      node = extract(h, node);
    }
  return node;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++) {
    mult[i] = i;
    multp[i] = 0;
  }
  
  int ptr = 0;
  for(int i = 1; i <= m; i++) {
    int op;
    std::cin >> op;
    if(op == 1) {
      int x, y;
      std::cin >> x >> y;
      assert(far[0][x] == 0);
      far[0][x] = y;
      mult[x] = y;
      multp[x] = 1;
    } else if(op == 2) {
      int x;
      std::cin >> x;
      ++ptr;
      start[ptr] = x;
      height[ptr] = getlevel(x);
    } else if(op == 3) {
      int x, y;
      std::cin >> x >> y;
      int target = getlevel(start[y]) - getlevel(x);
      if((target <= height[y] && 0 <= target) && raise(start[y], target) == x)
        std::cout << "YES\n";
      else
        std::cout << "NO\n";
    }
  }
  return 0;
}