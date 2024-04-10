#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>


using ll = long long;

int const lgmax = 20;
int const nmax = 1000000;
std::string v[5 + nmax];
int pref[5 + nmax];
int far[1 + lgmax][5 + nmax];
int n, r, c;

int eval(int from, int to) {
  if(to < from)
    return 1;
  return (pref[to] - pref[from - 1] + (to - from)) <= c;
}

int solve(int start, int steps) {
  int init = start;
  for(int h = lgmax; 0 <= h; h--)
    if((1 << h) & steps) {
      start = far[h][start];
    }
  return start - init;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cin >> n >> r >> c;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    pref[i] = pref[i - 1] + v[i].size();
  int ptr = 0;
  for(int i = 1;i <= n; i++) {
    while(ptr < n && eval(i, ptr + 1) == 1)
      ptr++;
    far[0][i] = ptr + 1;
  }

  far[0][n + 1] = n + 1;
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1; i <= n + 1; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
  
  int start = 1, l = 0;
  for(int i = 1;i <= n; i++) {
    int acc = solve(i, r);
    if(l < acc) {
      start = i;
      l = acc;
    }
  }

  int sz = 0;
  for(int i = start; i < start + l; i++) {
    if(sz == 0) {
      std::cout << v[i];
      sz = v[i].size();
    } else if(sz + v[i].size() + 1 <= c) {
      std::cout << " " << v[i];
      sz += v[i].size() + 1;
    } else {
      std::cout << '\n';
      std::cout << v[i];
      sz = v[i].size();
    }
  }
  return 0;
}