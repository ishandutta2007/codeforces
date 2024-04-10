#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
#include <set>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

std::map<std::pair<int,int>, int> freq;
int const nmax = 100000;
int const modulo = 1000000009;
std::pair<int,int> v[1 + nmax];

int _count(int id) {
  int x = v[id].first;
  int y = v[id].second;
  if(y == 0)
    return 3;
  return (0 < freq[{x - 1, y - 1}]) + (0 < freq[{x, y - 1}]) + (0 < freq[{x + 1, y - 1}]);
}

int stable(int x, int y) {
  if(0 < freq[{x, y}])
    return 1 < _count(freq[{x, y}]);
  return 1;
}

int can_remove(int x, int y) {
  if(0 == freq[{x, y}])
    return 0;
  return (stable(x - 1, y + 1) && stable(x, y + 1) && stable(x + 1, y + 1));
}

int main() {
  //std::ios::sync_with_stdio(0);
  //std::cin.tie(0);
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i].first >> v[i].second;
    freq[v[i]] = i;
  }

  int result = 0;
  std::set<int> myset;
  for(int i = 1; i <= n; i++)
    if(can_remove(v[i].first, v[i].second)) {
      myset.insert(i);
    }
  for(int i = 1; i <= n; i++) {
    std::set<int>::iterator it;
    if(i % 2 == 1) {
      it = myset.end();
      it--;
    } else
      it = myset.begin();
    int id = *it;
    myset.erase(it);
    result = (1LL * result * n + (id - 1)) % modulo;
    freq[{v[id].first, v[id].second}] = 0;
    for(int h = -1; h <= 1; h++) {
      int new_id = freq[{v[id].first + h, v[id].second - 1}];
      if(0 == new_id)
        continue; 
      if(can_remove(v[id].first + h, v[id].second - 1) == 1)
        myset.insert(new_id);
      else
        myset.erase(new_id);
    }

    for(int h = -2; h <= 2; h++) {
      int new_id = freq[{v[id].first + h, v[id].second}];
      if(0 == new_id)
        continue; 
      if(can_remove(v[id].first + h, v[id].second) == 1)
        myset.insert(new_id);
      else
        myset.erase(new_id);
    }
  }
  std::cout << result;
  return 0;
}