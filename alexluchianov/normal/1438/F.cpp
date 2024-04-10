#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <map>

using ll = long long;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int myrand(int lim) {
  return std::uniform_int_distribution<int>(1, lim)(rng);
}

int ask(int x, int y, int z) {
  std::cout << "? " << x << " " << y << " " << z << std::endl;
  int val;
  std::cin >> val;
  return val;
}

int main() {
  int h;
  std::cin >> h;
  int n = (1 << h) - 1;
  std::map<int,int> mp;
  
  for(int i = 1;i <= 420; i++) {
    int x = myrand(n), y = myrand(n), z = myrand(n);
    while(x == y)
      y = myrand(n);
    while(x == z || y == z)
      z = myrand(n);
    mp[ask(x, y, z)]++;
  }
  std::vector<std::pair<int,int>> v;
  for(std::map<int,int>::iterator it = mp.begin(); it != mp.end(); it++) {
    v.push_back({it->second, it->first});
  }
  std::sort(v.begin(), v.end());
  std::reverse(v.begin(), v.end());
  int root1 = v[0].second, root2 = v[1].second;
  for(int i = 1;i <= n; i++)
    if(root1 != i && root2 != i && ask(root1, root2, i) == i) {
      std::cout << "! " << i << std::endl;
    }
  return 0;
}