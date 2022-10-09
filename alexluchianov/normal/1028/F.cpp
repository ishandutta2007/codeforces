#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using ll = long long;

int const nmax = 200000;
int ptr = 0;
std::map<ll, int> mp;
std::vector<std::pair<int,int>> g[1 + nmax];
std::map<std::pair<int,int>, int> sol;

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  int active = 0;
  for(int t = 1;t <= n; t++) {
    int op, x, y;
    std::cin >> op >> x >> y;
    ll code = 1LL * x * x + 1LL * y * y;
    if(op == 1) {
      int d = std::__gcd(x, y);
      sol[{x / d, y / d}]++;

      if(mp[code] == 0) {
        mp[code] = ++ptr;
        g[ptr].push_back({x, y});
      } else {
        int val = mp[code];
        g[val].push_back({x, y});
        for(int i = 0; i + 1 < g[val].size(); i++) {
          int x2 = g[val][i].first + x;
          int y2 = g[val][i].second + y;
          int d = std::__gcd(x2, y2);
          sol[{x2 / d, y2 / d}] += 2;
        }
      }
      active++;
    } else if(op == 2) {
      int val = mp[code];
      int d = std::__gcd(x, y);

      sol[{x / d, y / d}]--;
      
      for(int i = 0; i < g[val].size(); i++)
        if(g[val][i].first == x && g[val][i].second == y) {
          g[val].erase(g[val].begin() + i);
          break;
        }
      for(int i = 0; i < g[val].size(); i++) {
        int x2 = g[val][i].first + x;
        int y2 = g[val][i].second + y;
        int d = std::__gcd(x2, y2);
        sol[{x2 / d, y2 / d}] -= 2;
      }
      active--;
    } else {
      int d = std::__gcd(x, y);
      std::cout << active - sol[{x / d, y / d}] << '\n';
    }
  }

  return 0;
}